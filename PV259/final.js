// Settings
const canvas = 400;

const breakChange = 0.1;
const breakChangeSpontaneous = 0.01;

const startSpeedMax = 10; // In pixels per second

const dimensions = 2; // 2 or 3

// Utils
function randNum(min, max) {
  max === undefined && ([ min, max ] = [ 0, min ]);
  
  return min + Math.floor(Math.random() * (max - min));
}

function randNumS(bound) { return randNum(1 - bound, bound); }

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
  
  for (let [ iMaybe, a0 ] of asteroids.entries()) {
    for (let [ jMaybe, a1 ] of asteroids.entries()) {
      if (a0 === a1) break;
      
      const colTime = detectCollision(a0, a1);
      
      if (colTime !== null && colTime < time) {
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
  
  const a = vel.reduce((a, c) => a + c ** 2);
  const b = 2 * (pos.reduce((a, c) => a + c) + vel.reduce((a, c) => a + c));
  const c = pos.reduce((a, c) => a + c ** 2) -
    (a0.radius + a1.radius) ** 2;
  
  const discriminant = Math.sqrt(b ** 2 - 4 * a * c);
  
  if (isNaN(discriminant)) return null;
  
  const colTime = -(b + discriminant) / 2 / a;
  
  return colTime < 0 ? null : colTime;
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
  
  move(dt) {
    for (let i = 0; i < this.position.length; i++) {
      this.position[i] += this.velocity[i] * dt;
    }
  }
  
  tick(time) {
    const collision = detectClosestCollision();
    const moveTime = Math.min(collision.time, time);
    
    for (let asteroid of asteroids) asteroid.move(moveTime);
    
    if (collision.time < time) {
      // TODO change direction of asteroids at collision.[ij]
      
      this.tick(time - collision.time);
    }
  }
}

function setup() {
  createCanvas(400, 400);
  
  for (let i = randNum(2, 10); i > 0; i--) {
    asteroids.push(new Asteroid(
      rand(canvas),
      randS(startSpeedMax),
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
      color(100, 100, 100),
    );
    
    asteroid.tick(deltaTime / 1000);
  }
}
