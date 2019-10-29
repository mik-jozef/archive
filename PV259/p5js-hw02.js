function rand(min, max) {
  if (max === undefined) [ min, max ] = [ 0, min ];
  
  return min + Math.floor((max - min) * Math.random());
}

function randS(max) {
  return rand(-max, max);
}

let canvas = 400;
let x = 0;
let y = 0;

let gravity = 0.01;

class Circle {
  constructor(x, y, size) {
    this.x = x;
    this.y = y;
    this.size = size;
  }
}

const paint = [];

function setup() {
  createCanvas(canvas, canvas);
  fill([ 0, 0, 0, 0 ]);
}

function draw() {
  background(220);
  
  const dX = mouseX - x;
  const dY = mouseY - y;
  const d = (dX ** 2 + dY ** 2) ** (1/2);
  const multiplier = deltaTime * d * gravity ** 2;
  
  x += Math.min(multiplier, 1) * dX;
  y += Math.min(multiplier, 1) * dY;
  
  circle(x, y, 50);
  
  if (paint.length >= 50) paint.pop();
  
  paint.unshift(new Circle(x + randS(10), y + randS(10), rand(30, 60)))
  
  paint.forEach((c, i) => {
    circle(c.x, c.y, c.size * i / paint.length)
  });
}
