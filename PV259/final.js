const canvas = 400;
const breakChange = 0.1;
const breakChangeSpontaneous = 0.01;

const dimensions = 2; // 2 or 3

function randNum(min, max) {
  max === undefined && ([ min, max] = [ 0, min ]);
  
  return min + Math.floor(Math.random() * (max - min));
}

function randNumS(bound) {
  return rand(1 - bound, bound);
}

function randHelper(f) {
  return (...args) => {
    const ret = [];
    
    for (let i = 0; i < dimensions; i++) {
      ret.push(f(...args));
    }
    
    return ret;
  }
}

const [ rand, randS ] = [ randNum, randNumS ].map(randHelper);

const asteroids = [];

class Asteroid {
  constructor(p, v, r) {
    this.position = p;
    this.velocity = v;
    this.radius = 10;
  }
  
  velocityAbs() {
    return Math.sqrt(this.velocity.map(a => a ** 2));
  }
  
  mass() {
    switch (dimension) {
      case 2: Math.PI * this.radius ** 2;
      case 3: Math.PI * this.radius ** 3 * 4 / 3;
      default: throw new Error("Dimension must be 2 or 3");
    }
  }
  
  momentum() {
    return this.mass() * this.velocityAbs();
  }
  
  detectCollision(iPtr) {
    for (let asteroid of asteroids) {
      if (this === asteroid) return false;
      
      // TODO
    }
  }
  
  move(dt) {
    for (let i = 0; i < this.position.length; i++) {
      this.position[i] += this.velocity[i] * dt;
    }
  }
  
  tick({ time, i0 = null, i1 = null }) {
    if (i0 !== null) {
      // TODO
      
      return;
    }
    
    const collision = { time: null, i0: null, i1: null };
    
    if (asteroids.some(asteroid => asteroid.detectCollision(collision))) {
      asteroids[i0].move(collision.time);
      asteroids[i1].move(collision.time);
      
      this.tick(time - collision.time);
      
      return;
    }
    
    for (let asteroid of asteroids) this.move(time);
  }
}

function setup() {
  createCanvas(400, 400);
  
  for (let i = randNum(2, 10); i > 0; i--) {
    asteroids.push(new Asteroid(
      rand(canvas),
      randS(10),
      randNum(15, 35),
    ));
  }
}

function draw() {
  background(220);
  
  for (let asteroid of asteroids) {
    circle(
      asteroid.position[0],
      asteroid.position[1],
      asteroid.radius,
      color(100, 100, 100)
    );
    
    asteroid.tick(deltaTime);
  }
}
