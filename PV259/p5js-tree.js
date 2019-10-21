const dirXMin = -10;
const dirXMax =  10;

const dirYMin = -10;
const dirYMax =  10;

const sizeMin = 30;
const sizeMax = 50;

const baseColor = [ 170, 150, 180 ];

const extraBranchChance = 0.1;
const branchDirChangeMax = 4;
const sizeChangeMax = 8;

const timeTreshold = 70;

const canvasSize = 500;

function rand(min, max) {
  if (max === undefined) [ min, max ] = [ 0, min ];
  
  return min + Math.floor(Math.random() * (max - min));
}

function randS(n) {
  return rand(-n, n);
}

const timer = {
  time: 0,
  add(time) {
    this.time += time;
    
    return this.time > timeTreshold && ((this.time -= timeTreshold), true);
  }
};

class Circle {
  constructor(x, y, color,
    size = rand(sizeMin, sizeMax),
    dirX = rand(dirXMin, dirXMax),
    dirY = rand(dirYMin, dirYMax),
  ) {
    this.x = x;
    this.y = y;
    
    this.color = color;
    this.size = size;
    
    this.dirX = dirX;
    this.dirY = dirY;
  }
  
}

let circles;
let cNew;

function setup() {
  circles = [
    new Circle(rand(0, canvasSize), rand(0, canvasSize), color(...baseColor)),
  ];
  
  cNew = [ circles[0] ];
  
  createCanvas(canvasSize, canvasSize);
}

function draw() {
  background(255);
  
  function growBranch(x, y, c = color(...baseColor), size, dX, dY) {console.log(size)
    if (size > 0) {
      const circle = new Circle(x, y, c, size, dX, dY);
      
      circles.push(circle);
      cNew.push(circle);
    }
  }
  
  function tick() {
    const oldNew = cNew;
    
    cNew = [];
    console.log(oldNew)
    oldNew.forEach(c => {console.log(c)
      growBranch(c.x + c.dirX, c.y + c.dirY,
        color(...baseColor), c.size, c.dirX, c.dirY);
      
      if (Math.random() < extraBranchChance) {
        const size = c.size - rand(sizeChangeMax);
        const dirX = c.dirX + randS(branchDirChangeMax);
        const dirY = c.dirY + randS(branchDirChangeMax);
        
        // TODO maybe modify this.dir[X|Y]?
        
        growBranch(c.x, c.y, color(...baseColor), size, dirX, dirY);
      }
    });
  }
  
  function draw() {
    circles.forEach(c => {
      fill(c.color);
      stroke(c.color);
      
      circle(c.x, c.y, c.size);
    });
  }
  
  timer.add(deltaTime) && tick();
  
  draw();
}
