const valMax = 100;

const low = [ 20, 20, 45 ];
const high = [ 35, 35, 75 ];

const colors = (() => {
  const colors = [];
  for (let x = 0; x < valMax; x++) colors.push(
    low.map((a, i) => Math.floor(a + (high[i] - a) * x / valMax)
  ));
  
  return colors;
})();

const c = 3; // Speed of light in px.
const canvasSize = 400;

const field = [];

function initField() {
  field.push([]);
  
  for (let x = 0; x < canvasSize; x++) {
    field[0].push(10 + random([ 0, 0, 0, 1, 1, 2, 3 ]));
  }
  
  for (let y = 1; y < canvasSize; y++) {
    field.push(nextRow(field[field.length - 1]));
  }
}

function nextRow(row) {
  const changes = row.map(a => 0);
  
  row.forEach((r, i) => {
    changes[i] += sum(row, i, c) > r * (2 * c + 1) ? -1 : 1;
  });
}

function sum(row, i, c) {
  let s = 0;
  
  for (let x = i - row; x <= i + row; x++) {
    s += row[(x + row.length) % row.length];
  }
  
  return s;
}

function setup() {
  initField();
  
  createCanvas(canvasSize, canvasSize);
}

function draw() {
  for (let x = 0; x < canvasSize; x++) {
    for (let y = 0; y < canvasSize; y++) {
      stroke(...colors[field[0][x][y]]);
      point(x, y);
    }
  }
  
  console.log("draw")
}
