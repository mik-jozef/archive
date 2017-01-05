program pohyb;
uses graph,math,crt;

var u,v,f1,f2:integer;

var x,y,addendX,addendY,maxX,maxY,position:integer;
var x0,x1,y0,y1,direction:integer;

var progress,numOfInterpolations:array[1..2]of integer;  //1=x, 2=y
var realProgress:real;

begin
randomize();

for f1:=1 to 10 do
  begin
  if keypressed=true then break;
  delay(100);
  end;

if f1<10 then
  begin
  write('Zadajte sirku Vasej obrazovky (px):');
  readln(maxX);
  write('Zadajte vysku vasej obrazovky (px):');
  readln(maxY);
  end
else
  begin
  maxX:=1366;
  maxY:=768;
  end;

x:=random(maxX)+1;
y:=random(maxY)+1;

position:=1;
progress[1]:=1;
progress[2]:=1;
numofInterpolations[1]:=random(41)+20;
numofInterpolations[2]:=random(41)+20;
x0:=random(21)-10;
x1:=random(21)-10;
y0:=random(21)-10;
y1:=random(21)-10;
direction:=1;

detectgraph(u,v);
initgraph(u,v,'');

while keypressed=false do
  begin
  if progress[1]>numOfInterpolations[1] then
    begin
    progress[1]:=1;
    numOfInterpolations[1]:=random(41)+20;
    x0:=x1;
    x1:=random(21)-10;
    end;

  if progress[2]>numOfInterpolations[2] then
    begin
    progress[2]:=1;
    numOfInterpolations[2]:=random(41)+20;
    y0:=y1;
    y1:=random(21)-10;
    end;


  realProgress:=progress[1]/numOfInterpolations[1];      //realProgress=(0,1>, next line makes difference between 0.5 and realProgress bigger (closer to 0/1 if realProgress is smaller/bigger than 0.5)
  realProgress:=10*realprogress*realProgress*realProgress-15*realProgress*realProgress*realProgress*realProgress+6*realProgress*realProgress*realProgress*realProgress*realProgress;
  addendX:=trunc(x0+(x1-x0)*realProgress+(maxX/2-x)/50);
  progress[1]:=progress[1]+1;


  realProgress:=progress[2]/numOfInterpolations[2];
  realProgress:=10*realprogress*realProgress*realProgress-15*realProgress*realProgress*realProgress*realProgress+6*realProgress*realProgress*realProgress*realProgress*realProgress;
  addendY:=trunc(y0+(y1-y0)*realProgress+(maxY/2-y)/50);
  progress[2]:=progress[2]+1;

  x:=x+addendX;
  y:=y+addendY;


  setcolor(green);
  circle(x,y,trunc(sqrt(power(abs(x-maxX/2),2)+power(abs(y-maxY/2),2))/10)+2);   //radius depends on distance from center of screen (distance=sqrt(a*a+b*b)),a=x from center, b=y from center
  delay(40);

  setcolor(black);
  circle(x,y,trunc(sqrt(power(abs(x-maxX/2),2)+power(abs(y-maxY/2),2))/10)+2);
  end;
end.