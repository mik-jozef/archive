const canvasMax = 600;

function setup() {
  createCanvas(canvasMax, canvasMax);
  noLoop();
}

function draw() {
  background(45, 45, 70);
  
  for (let i = 3 + random(5); i > 0; i--) {
    addCircleRay(
      random(canvasMax), random(canvasMax),
      10 + random(70), 10 + random(70),
      random() / 2 + 0.75,
      randColor(), randColor(),
    );
  }
}

function addCircleRay(x, y, diffX, diffY, multSize, color0, color1) {
  if (x < -100 || y < -100 || x > canvasMax + 100 || y > canvasMax + 100) return;
  if (diffX + diffY < 1) return;
  
  fill(color0);
  circle(x, y, (diffX ** 2+ diffY ** 2) ** (1/2));
  
  addCircleRay(
    x + diffX, y + diffY,
    diffX * multSize, diffY * multSize,
    multSize, color1, color0
  );
}

function randColor() {
  return color(random(255), random(255), random(255));
}
