const tau = 2 * Math.PI;
const animTime = 0.3;
const displacement = 7;
const colors = true;

function smoothstep(x) {
  return 3 * x ** 2 - 2 * x ** 3;
}

function setup() {
  createCanvas(400, 400);
}

function drawPiecedCircle(pieces, size, time, frac, c) {
  for (let i = 0; i < pieces; i++) {
    let dx = Math.cos(tau * (i + 0.5) / pieces) * displacement;
    let dy = Math.sin(tau * (i + 0.5) / pieces) * displacement;
    
    let m; // `dx` and `dy` will be multiplied by `m`.
    
    function animateMiddle() {
      switch (true) {
        case frac < animTime / 2: return 0.5 + frac / animTime;
        case 1 - frac < animTime / 2: return 0.5 - (frac - 1) / animTime;
        default: return 1;
      }
    }
    
    switch (i - time) {
      case -1: m = Math.max(0.5 - frac / animTime, 0); break;
      case 0: m = animateMiddle(); break;
      case 1: m = Math.max(0.5 + (frac - 1) / animTime, 0); break;
      default: m = 0; break;
    }
    
    dx *= smoothstep(m);
    dy *= smoothstep(m);
    
    fill(colors && c && i == time ? c : color(255, 255, 255))
    arc(200 + dx, 200 + dy, size, size, tau * i / pieces, tau * (i + 1) / pieces);
  }
}

function draw() {
  const millisFrac = new Date().getMilliseconds() / 1000;
  
  background(220);
  
  drawPiecedCircle(60, 175, second(), millisFrac);
  drawPiecedCircle(60, 150, minute(), (second() + millisFrac) / 60, color(255, 205, 110));
  drawPiecedCircle(12, 100, hour() % 12, minute() / 60, color(255, 205, 95));
}
