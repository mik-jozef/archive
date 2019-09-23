const low = [ 20, 20, 45 ];
const high = [ 35, 35, 75 ];

const canvasSize = 400;

const field = [];

function getColor(x) {
  return Math.floor(low.map((a, i) => a + (high[i] - a) * x));
}

function setup() {
  initField();
  
  createCanvas(canvasSize, canvasSize);
}

function draw() {
  
}
