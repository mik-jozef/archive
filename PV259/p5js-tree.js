const dirXMin = -10;
const dirXMax =  10;

const dirYMin = -10;
const dirYMax =  10;

const sizeMin = 30;
const sizeMax = 50;

function rand(min, max) {
  return min + Math.floor(Math.random() * (max - min));
}

class Tree {
  constructor(x, y, color,
    size = rand(sizeMin, sizeMax),
    dirX = rand(dirXMin, dirXMax),
    dirY = rand(dirYMin, dirYMax),
  ) {
    this.children = [];
    
    this.x = x;
    this.y = y;
    this.size = size;
    this.dirX = dirX;
    this.dirY = dirY;
  }
  
  growBranch(a) {
    const x = this.x + this.size * Math.cos(a);
    const y = this.y + this.size * Math.sin(a);
    
    this.children.push(new Tree(x, y));
  }
  
  tick(delta) {
    // TODO
    
    return this;
  }
  
  draw(circle) {
    circle(this.x, this.y, this.size)
  }
}

let root;

function setup() {
  root = new Tree(rand(0, 400), rand(0, 400), color(150));
  
  createCanvas(400, 400);
}

function draw() {
  background(255);
  
  root.tick(deltaTime).draw(circle);
}
