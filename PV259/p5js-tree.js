const dirXMin = -10;
const dirXMax =  10;

const dirYMin = -10;
const dirYMax =  10;

const sizeMin = 30;
const sizeMax = 50;

const baseColor = [ 170, 150, 180 ];

const extraBranchChance = 0.05;

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
    this.color = color;
    this.size = size;
    this.dirX = dirX;
    this.dirY = dirY;
  }
  
  growBranch(x, y) {
    this.children.push(new Tree(x, y, color(...baseColor)));
  }
  
  tick(delta, mouseX, mouseY) {
    this.children.forEach(a => a.tick(delta, mouseX, mouseY));
    
    if (this.children.length = 0) {
      growBranch(this.x + this.dirX, this.y + this.dirY, color(...baseColor));
      
      if (Math.random() < extraBranchChance) growBranch();
    }
    
    return this;
  }
  
  draw(circle, stroke, fill) {
    fill(this.color);
    stroke(this.color);
    
    circle(this.x, this.y, this.size);
    
    this.children.forEach(a => a.draw(circle, stroke, fill));
  }
}

let root;

function setup() {
  root = new Tree(rand(0, 400), rand(0, 400), color(...baseColor));
  
  createCanvas(400, 400);
}

function draw() {
  background(255);
  
  root.tick(deltaTime, mouseX, mouseY).draw(circle, stroke, fill);
}
