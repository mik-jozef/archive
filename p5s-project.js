const low = [ 20, 20, 45 ];
const high = [ 35, 35, 75 ];

const canvasSize = 400;

const field = [];

function initField() {
  const fieldTmp = [];
  
  for (let x = 0; x < canvasSize; x++) {
    fieldTmp[x] = [];
    
    for (let y = 0; y < canvasSize; y++) {
      fieldTmp[x][y] = 0.1;
    }
  }
  
  field[0] = deepCopy(fieldTmp);
  field[1] = deepCopy(fieldTmp);
}

function getColor(x) {
  return low.map((a, i) => Math.floor(a + (high[i] - a) * x));
}

function setup() {
  initField();
  
  createCanvas(canvasSize, canvasSize);
}

function draw() {
  for (let x = 0; x < canvasSize; x++) {
    for (let y = 0; y < canvasSize; y++) {
      fill(...getColor(field[0][x][y]));
      line(x, y, x, y);
    }
  }
}

function deepCopy(x) {
  if (x.length) return x.map(a=> deepCopy(a));
  
  return x;
}
