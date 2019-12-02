"use strict";

p5.disableFriendlyErrors = true;


// Settings
let displayCircles = true;

const canvas = 400;

const [ asteroidMin, asteroidMax ] = [ 2, 3 ];
const [ radiusMin, radiusMax ] = [ 10, 15 ];
const startSpeedMax = 10; // In pixels per second

const doCollisions = false;

const G = 30; // Gravitational constant in cubic pixels per kilogram per second squared.
const L = 5; // Light-bending constant in whatever.

const bgImagePath = "asdf.jpg";
const ignoreRadiusDefault = 10;

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
let distortedImage;

function detectClosestCollision() {
  let time = Infinity;
  let i = null;
  let j = null;
  
  if (doCollisions) {
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

function getGravityAt(x, y, time = 1, ignoreRadius = ignoreRadiusDefault) {
  const g = [ 0, 0 ];
  
  for (let asteroid of asteroids) {
    const r = Math.sqrt((asteroid.position[0] - x) ** 2 + (asteroid.position[1] - y) ** 2);
    
    if (r <= (ignoreRadius === ignoreRadiusDefault ? ignoreRadiusDefault : ignoreRadius + asteroid.radius)) continue;
    
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
  
  momentum() { return this.velocity.map(a => a * this.mass()) }
  
  updateVelocity(time) {
    const g = getGravityAt(this.position[0], this.position[1], time, doCollisions ? this.radius : ignoreRadiusDefault);
    
    this.velocity[0] += g[0];
    this.velocity[1] += g[1];
  }
  
  move(dt) {
    for (let i = 0; i < this.position.length; i++) {
      this.position[i] += this.velocity[i] * dt;
    }
  }
  
  handleCollision(a, b) {
    function dotProduct(a, b) {
      let ret = 0;
      
      for (let i = 0; i < a.length; i++) {
        ret += a[i] * b[i];
      }
      
      return ret;
    }
    
    // en.wikipedia.org/wiki/Elastic_collision#Two-dimensional
    
    const massTotal = a.mass() + b.mass();
    
    const dPosA = minus(a.position, b.position);
    const dPosB = minus(b.position, a.position);
    
    const massA = 2 * b.mass() / massTotal;
    const massB = 2 * a.mass() / massTotal;
    
    const oA = dotProduct(minus(a.velocity, b.velocity), dPosA);
    const oB = dotProduct(minus(b.velocity, a.velocity), dPosB);
    
    const magSquared = dPosA[0] ** 2 + dPosA[1] ** 2;
    
    a.velocity = minus(a.velocity, dPosA.map(a => a * massA * oA / magSquared));
    b.velocity = minus(b.velocity, dPosB.map(b => b * massB * oB / magSquared));
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
  
  distortedImage = createImage(canvas, canvas);
  distortedImage.loadPixels();
  
  let momentum = [ 0, 0 ];
  
  for (let i = randNum(asteroidMin, asteroidMax); i > 0; i--) {
    const radius = randNum(radiusMin, radiusMax);
    
    if (i == 1) {
      asteroids.push(
        new Asteroid(
          rand(radius, canvas - radius),
          momentum.map(a => -a / Math.PI / radius ** 2),
          radius,
        ),
      );
    } else {
      const asteroid =
        new Asteroid(rand(radius, canvas - radius), randS(startSpeedMax), radius);
      
      momentum = plus(momentum, asteroid.momentum());
      
      asteroids.push(asteroid);
    }
  }
}

function draw() {
  for (let x = 0; x < canvas; x += 1) {
    for (let y = 0; y < canvas; y += 1) {
      const g = getGravityAt(x, y).map(a => Math.floor(a * L), 0);
      const i = 4 * ((y + g[1]) * canvas + x + g[0]);
      
      if (0 <= x + g[0] && x + g[0] < canvas
          && 0 <= y + g[1] && y + g[1] < canvas) {
        distortedImage.pixels[4 * (y * canvas + x)] = bgImage.pixels[i];
        distortedImage.pixels[4 * (y * canvas + x) + 1] = bgImage.pixels[i + 1];
        distortedImage.pixels[4 * (y * canvas + x) + 2] = bgImage.pixels[i + 2];
      } else {
        distortedImage.pixels[4 * (y * canvas + x)] =
          distortedImage.pixels[4 * (y * canvas + x) + 1] =
          distortedImage.pixels[4 * (y * canvas + x) + 2] = 0;
      }
      
      distortedImage.pixels[4 * (y * canvas + x) + 3] = 255;
    }
  }
  
  distortedImage.updatePixels();
  image(distortedImage, 0, 0);
  
  for (let asteroid of asteroids) {
    stroke(0, 0, 0);
    
    displayCircles && circle(
      asteroid.position[0],
      asteroid.position[1],
      asteroid.radius * 2,
      color(100, 100, 100),
    );
    
    asteroid.tick(deltaTime / 1000);
  }
}
