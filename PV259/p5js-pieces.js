const pieces = 12;
const size = 100;
const tau = 2 * Math.PI;
const period = 3000;
const tide = 30;

function between(a, min, max) {
  return min < a && a < max;
}

function setup() {
  createCanvas(400, 400);
}

function draw() {
  const time = millis() / period;
  background(220);
  
  for (let i = 0; i < pieces; i++) {
    const dx = Math.sin(tau * (time + i / pieces)) * Math.sin(time / 3) * 50;
    const dy = Math.cos(tau * (time + i / pieces)) * Math.sin(time / 3) * 50;
    
    arc(200 + dx, 200 + dy, size, size, tau * i / pieces, tau * (i + 1) / pieces);
  }
}
