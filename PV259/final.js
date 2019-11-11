// Settings
const canvas = 400;
const breakChange = 0.1;
const breakChangeSpontaneous = 0.01;

const dimensions = 2; // 2 or 3

// Utils
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

function plus(arr0, arr1) { return arr0.map((a, i) => a + arr1[i]) }
function minus(arr0, arr1) { return arr0.map((a, i) => a - arr1[i]) }

// Program
const asteroids = [];

function detectClosestCollision() {
  let time = Infinity;
  let i = null;
  let j = null;
  
  for (let [ a0, iMaybe ] of asteroids.entries()) {
    for (let [ a1, jMaybe ] of asteroids.entries()) {
      if (a0 === a1) break;
      
      const pos = minus(a0.position, a1.position)
      const vel = minus(a0.velocity, a1.velocity);
      
      const a = vel.reduce((a, c) => a + c ** 2);
      const b = 2 * (pos.reduce((a, c) => a + c) + vel.reduce((a, c) => a + c));
      const c = pos.reduce((a, c) => a + c ** 2)
        - (a0.radius + a1.radius) ** 2;
      
      const discriminant = Math.sqrt(b ** 2 - 4 * a * c);
      
      if (isNaN(discriminant)) break;
      
      const colTime = -(b + discriminant) / 2 / a;
      
      if (colTime < 0 || colTime > time) break;
      
      time = colTime;
      indexI = iMaybe;
      indexJ = jMaybe;
    }
  }
  
  return { time, i, j };
}

function detectCollision(a, b) {

}

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
      case 2: return Math.PI * this.radius ** 2;
      case 3: return Math.PI * this.radius ** 3 * 4 / 3;
      default: throw new Error("Dimension must be 2 or 3");
    }
  }
  
  momentum() {
    return this.mass() * this.velocityAbs();
  }
  
  detectCollision(maxTime, collision) {
    for (let [ asteroid, i ] of asteroids.entries()) {
      if (this === asteroid) return false;
      
      const pos = minus(asteroid.position, this.position)
      const vel = minus(asteroid.velocity, this.velocity);
      
      const a = vel.reduce((a, c) => a + c ** 2);
      const b = 2 * (pos.reduce((a, c) => a + c) + vel.reduce((a, c) => a + c));
      const c = pos.reduce((a, c) => a + c ** 2)
        - (asteroid.radius + this.radius) ** 2;
      
      const discriminant = Math.sqrt(b ** 2 - 4 * a * c);
      
      if (isNaN(discriminant)) return false;
      
      const colTime = -(b + discriminant) / 2 / a;
      
      if (colTime < 0 || colTime > maxTime) return false;
      
      collision.time = colTime;
      collision.index = i;
      
      return true;
    }
  }
  
  move(dt) {
    for (let i = 0; i < this.position.length; i++) {
      this.position[i] += this.velocity[i] * dt;
    }
  }
  
  tick(time) {
    const collision = { time: null, i0: null, i1: null };
    
    if (asteroids.some(asteroid => asteroid.detectCollision(time, collision))) {
      for ()
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
