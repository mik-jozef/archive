const canvas = 400;
const breakChange = 0.1;
const breakChangeSpontaneous = 0.01;

function rand(min, max) {
  max === undefined && ([ min, max] = [ 0, min ]);
  
  return min + Math.floor(Math.random() * (max - min));
}

function randS(bound) {
  return rand(1 - bound, bound);
}

const asteroids = [];

class Asteroid {
  constructor(x, y) {
    this.x = rand(canvas);
    this.y = rand(canvas);
    
    this.dx = randS(10);
    this.dy = randS(10);
    
    this.radius = ;
  }
  
  velocity() {
    return Math.sqrt(this.dx ** 2 + this.dy ** 2);
  }
  
  mass() {
    return Math.PI * this.radius ** 2;
  }
  
  momentum() {
    return this.mass() * this.velocity();
  }
  
  detectCollision() {
    for (let asteroid of asteroids) {
      if (this == asteroid) break;
    }
  }
  
  tick(dt) {
    handleCollision()
  }
}

function setup() {
  createCanvas(400, 400);
  
  asteroids.push(new Asteroid());
}

function draw() {
  background(220);
  
  for (let asteroid of asteroids) {
    circle(asteroid.x, asteroid.y, asteroid.radius, color(100, 100, 100));
    
    asteroid.tick(deltaTime);
  }
}
