const tau = 2 * Math.PI;
const fracScale = 0.3;
const displacement = 50;

function curve(x) {
  return 3 * x ** 2 - 2 * x ** 3;
}

function setup() {
  createCanvas(400, 400);
}

function drawPiecedCircle(pieces, size, time, frac) {
  for (let i = 0; i < pieces; i++) {
    let dx = Math.sin(tau * i / pieces) * displacement;
    let dy = Math.cos(tau * i / pieces) * displacement * -1;
    
    switch (i - time) {
      case -1: break;
      case 0: break;
      case 1: break;
      default: dxMa
    }
    
    arc(200 + dx, 200 + dy, size, size, tau * i / pieces, tau * (i + 1) / pieces);
  }
}

function draw() {
  const millisFrac = new Date().getMilliseconds() / 1000;
  
  background(220);
  
  drawPiecedCircle(12, 150, hour() % 12, minute() / 60 + second() / 3600);
  drawPiecedCircle(60, 100, minute(), (second() + millisFrac) / 60);
  drawPiecedCircle(60, 170, second(), millisFrac);
}
