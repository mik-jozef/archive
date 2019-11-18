"use strict";

p5.disableFriendlyErrors = true;

// Settings
const canvas = 200;
const [ asteroidMin, asteroidMax ] = [ 2, 3 ];
const [ radiusMin, radiusMax ] = [ 10, 15 ];
const startSpeedMax = 10; // In pixels per second

const G = 20; // Gravitational constant in cubic pixels per kilogram per second squared.
const L = 5; // Light-bending constant in whatever.

const bgImagePath = "asdf.jpg";

// Utils
function randNum(min, max) {
  max === undefined && ([ min, max ] = [ 0, min ]);
  
  return min + Math.floor(Math.random() * (max - min));
}

function randNumS(bound) { return randNum(1 - bound, bound); }

function rand(...args) { return [ randNum(...args), randNum(...args) ] }
function randS(...args) { return [ randNumS(...args), randNumS(...args) ] }

function plus(arr0, arr1) { return arr0.map((a, i) => a + arr1[i]) }
function minus(arr0, arr1) { return arr0.map((a, i) => a - arr1[i]) }

function velocityAfterCollision(m0, m1, v0, v1) {
  const m = m0 + m1;
  
  return [ ((m0 - m1) * v0 + 2 * m1 * v1) / m, (2 * m1 * v0 + (m1 - m0) * v1) / m ];
}

// Program
const asteroids = [];

let bgImage;

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
  const [ pos, vel ] = [ minus(a0.position, a1.position), minus(a0.velocity, a1.velocity) ];
  
  const a = vel[0] ** 2 + vel[1] ** 2;
  const b = 2 * (vel[0] * pos[0] + vel[1] * pos[1]);
  const c = pos[0] ** 2 + pos[1] ** 2 - (a0.radius + a1.radius) ** 2;
  
  const discriminant = Math.sqrt(b ** 2 - 4 * a * c);
  
  return -(b + discriminant) / 2 / a;
}

function getGravityAt(x, y, time = 1, ignoreRadius = 0) {
  const g = [ 0, 0 ];
  
  for (let asteroid of asteroids) {
    const r = Math.sqrt((asteroid.position[0] - x) ** 2 + (asteroid.position[1] - y) ** 2);
    
    if (r <= ignoreRadius) continue;
    
    const mass = asteroid.mass();
    
    g.forEach((a, i) => g[i] += (asteroid.position[i] - [ x, y ][i]) * G * time * mass / r ** 3);
  }
  
  return g;
}

class Asteroid {
  constructor(p, v, r) {
    this.position = p;
    this.velocity = v;
    this.radius = r;
  }
  
  mass() { return Math.PI * this.radius ** 2 }
  
  updateVelocity(time) {
    const g = getGravityAt(this.position[0], this.position[1], time, this.radius);
    
    this.velocity[0] += g[0];
    this.velocity[1] += g[1];
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
    
    const mMatrix = [ v, [ -v[0], v[1] ] ];
    const mInverse = [];
    
    const base = [ v ];
    
    for (let i = 0; i < 2; i++) {
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

function preload() {
  bgImage = loadImage(bgImagePath);
}

function setup() {
  createCanvas(canvas, canvas);
  bgImage.resize(canvas, canvas);
  bgImage.loadPixels();
  
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
  const step = 1;
  
  for (let x = 0; x < canvas; x += step) {
    for (let y = 0; y < canvas; y += step) {
      const g = getGravityAt(x, y).map(a => Math.floor(a * L));
      const i = 4 * ((y + g[1]) * canvas + x + g[0]);
      
      if (0 <= i && i + 2 < bgImage.pixels.length) {
        stroke(bgImage.pixels[i], bgImage.pixels[i + 1], bgImage.pixels[i + 2]);
      } else stroke(0, 0, 0);
      
      point(x, y);
    }
  }
  
  for (let asteroid of asteroids) {
    stroke(0, 0, 0);
    
    circle(
      asteroid.position[0],
      asteroid.position[1],
      asteroid.radius * 2,
      color(100, 100, 100),
    );
    
    asteroid.tick(deltaTime / 1000);
  }
}
