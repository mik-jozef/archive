"use strict";

// Settings
const canvas = 400;
const [ asteroidMin, asteroidMax ] = [ 4, 5 ];
const [ radiusMin, radiusMax ] = [ 10, 15 ];
const startSpeedMax = 10; // In pixels per second

const dimensions = 2; // 2 or 3

const G = 20; // Gravitational constant in cubic pixels per kilogram per second squared

// Utils
function randNum(min, max) {
  max === undefined && ([ min, max ] = [ 0, min ]);
  
  return min + Math.floor(Math.random() * (max - min));
}

function randNumS(bound) { return randNum(1 - bound, bound); }

const randHelper = (f) => (...args) => {
  const ret = [];
  
  for (let i = 0; i < dimensions; i++) {
    ret.push(f(...args));
  }
  
  return ret;
}

const [ rand, randS ] = [ randNum, randNumS ].map(randHelper);

function plus(arr0, arr1) { return arr0.map((a, i) => a + arr1[i]) }
function minus(arr0, arr1) { return arr0.map((a, i) => a - arr1[i]) }

function velocityAfterCollision(m0, m1, v0, v1) {
  const m = m0 + m1;
  
  return [ ((m0 - m1) * v0 + 2 * m1 * v1) / m, (2 * m1 * v0 + (m1 - m0) * v1) / m ];
}

// Program
const asteroids = [];

function detectClosestCollision() {
  let time = Infinity;
  let i = null;
  let j = null;
  
  for (let [ iMaybe, a0 ] of asteroids.entries()) {
    for (let [ jMaybe, a1 ] of asteroids.entries()) {
      if (a0 === a1) break;
      
      const colTime = detectCollision(a0, a1);
      
      if (0 <= colTime && colTime < time) {
        time = colTime;
        i = iMaybe;
        j = jMaybe;
      }
    }
  }
  
  return { time, i, j };
}

function detectCollision(a0, a1) {
  const pos = minus(a0.position, a1.position)
  const vel = minus(a0.velocity, a1.velocity);
  
  const a = vel.reduce((a, c) => a + c ** 2, 0);
  const b = 2 * pos.reduce((a, c, i) => a + c * vel[i], 0);
  const c = pos.reduce((a, c) => a + c ** 2, 0) - (a0.radius + a1.radius) ** 2;
  
  const discriminant = Math.sqrt(b ** 2 - 4 * a * c);
  
  return -(b + discriminant) / 2 / a;
}

class Asteroid {
  constructor(p, v, r) {
    this.position = p;
    this.velocity = v;
    this.radius = r;
  }
  
  mass() {
    switch (dimensions) {
      case 2: return Math.PI * this.radius ** 2;
      case 3: return Math.PI * this.radius ** 3 * 4 / 3;
      default: throw new Error("Dimension must be 2 or 3");
    }
  }
  
  updateVelocity(time) {
    for (let asteroid of asteroids) {
      if (minus(this.position, asteroid.position).reduce((a, c) => a + c ** 2, 0)
        < (this.radius + asteroid.radius) ** 2) continue;
      
      const mass = asteroid.mass();
      const rSquared = minus(asteroid.position, this.position).reduce((a, c) => a + c ** 2, 0);
      
      for (let i = 0; i < dimensions; i++) {
        this.velocity[i] += Math.sign(asteroid.position[i] - this.position[i]) * time * G * mass / rSquared;
      }
    }
  }
  
  move(dt) {
    for (let i = 0; i < this.position.length; i++) {
      this.position[i] += this.velocity[i] * dt;
    }
  }
  
  handleCollision(a, b) {
    const aVel = a.velocity;
    const bVel = b.velocity;
    
    const v = (() => {
      const v = minus(aVel, bVel);
      const abs = Math.sqrt(v.reduce((a, c) => a + c ** 2, 0));
      
      return v.map(v => v / abs);
    })();
    
    if (dimensions == 2) {
      const mMatrix = [ v, [ -v[0], v[1] ] ];
      const mInverse = [];
    } else {
      // TODO 3D case
    }
    const base = [ v ];
    
    for (let i = 0; i < dimensions; i++) {
      [ a.velocity[i], b.velocity[i] ] = velocityAfterCollision(
        a.mass(),
        b.mass(),
        a.velocity[i],
        b.velocity[i],
      );
    }
  }
  
  tick(time) {
    for (let asteroid of asteroids) asteroid.updateVelocity(time);
    
    const collision = detectClosestCollision();
    const moveTime = Math.min(collision.time, time);
    
    for (let asteroid of asteroids) asteroid.move(moveTime);
    
    if (collision.time < time) {
      this.handleCollision(asteroids[collision.i], asteroids[collision.j]);
      
      this.tick(time - collision.time);
    }
  }
}

function setup() {
  createCanvas(400, 400);
  
  for (let i = randNum(asteroidMin, asteroidMax); i > 0; i--) {
    const radius = randNum(radiusMin, radiusMax);
    
    asteroids.push(new Asteroid(
      rand(radius, canvas - radius),
      randS(startSpeedMax),
      radius,
    ));
  }
}

function draw() {
  background(220);
  
  for (let asteroid of asteroids) {
    circle(
      asteroid.position[0],
      asteroid.position[1],
      asteroid.radius * 2,
      color(100, 100, 100),
    );
    
    asteroid.tick(deltaTime / 1000);
  }
}
