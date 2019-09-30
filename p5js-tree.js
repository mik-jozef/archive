class Tree {
  constructor(x, y, size = 0) {
    this.children = [];
    
    this.x = x;
    this.y = y;
    this.size = size;
  }
  
  growBranch(a) {
    const x = this.x + this.size * Math.cos(a);
    const y = this.y + this.size * Math.sin(a);
    
    this.children.push(new Tree(x, y));
  }
  
  tick() {
    
  }
}

function setup() {
  createCanvas(400, 400);
}

function draw() {
  background(220);
}
