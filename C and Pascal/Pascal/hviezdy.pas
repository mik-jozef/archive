program hviezdy;
uses graph,crt,math;

var u,v,f1,fx,fy,position:integer;
var x,y,r:array[0..200]of integer;

begin
randomize();
detectgraph(u,v);
initgraph(u,v,'');

while keypressed=false do
  begin
  setcolor(random(15)+16);
  x[position]:=random(1366);
  y[position]:=random(768);
  r[position]:=trunc(sqr(random(10))/10)+1;
  if random(50)=0 then r[position]:=r[position]+20;
  if r[position] mod 2=1 then r[position]:=r[position]+1;


  for fx:=x[position]-trunc(r[position]/2) to x[position]+trunc(r[position]/2) do
    begin
    for fy:=y[position]-trunc(r[position]/2) to y[position]+trunc(r[position]/2) do
      begin
      if abs(fx-x[position])*abs(fy-y[position])<r[position]/3 then
        line(fx,fy,fx,fy);
      end;
    end;

  setcolor(black);
  if position=200 then
    begin
    for fx:=x[0]-trunc(r[0]/2) to x[0]+trunc(r[0]/2) do
      begin
      for fy:=y[0]-trunc(r[0]/2) to y[0]+trunc(r[0]/2) do
        begin
        if abs(fx-x[0])*abs(fy-y[0])<r[0]/3 then
          line(fx,fy,fx,fy);
        end;
      end;
    end
  else
    begin
    for fx:=x[position+1]-trunc(r[position+1]/2) to x[position+1]+trunc(r[position+1]/2) do
      begin
      for fy:=y[position+1]-trunc(r[position+1]/2) to y[position+1]+trunc(r[position+1]/2) do
        begin
        if abs(fx-x[position+1])*abs(fy-y[position+1])<r[position+1]/3 then
          line(fx,fy,fx,fy);
        end;
      end;
    end;

  if position=200 then
    position:=0
  else
    position:=position+1;

  delay(random(40)+80);
  end;
readln();
end.