program matrix;
uses graph, crt, math;

var u,v:integer;

var currentLoopNumber,x,y:integer;
var charLayer,currentCharLayer,charHeight,charWidth:integer;
var arrayIndex:integer;

var greenMode:boolean;

var letterArray:array[0..120]of integer;
var charLengths:array[0..120]of integer;

begin
randomize();

writeln('Greenmode? (1=yes)');
readln(charLayer);

if charLayer=1 then
  begin
  greenMode:=true;
  end;


charLayer:=70;
charHeight:=15;
charWidth:=10;

detectGraph(u,v);
initGraph(u,v,'');

for arrayIndex:=0 to 120 do
  begin
  letterArray[arrayIndex]:=-1;
  if greenMode then
    begin
    charLengths[arrayIndex]:=random(20)+14
    end
  else
    begin
    charLengths[arrayIndex]:=16
    end;
  end;

while keypressed=false do
  begin
  for arrayIndex :=0 to 120 do
    begin
    if (letterArray[arrayIndex]=-1) then
      begin
      if random(200)=0 then
        begin
        letterArray[arrayIndex]:=0;
        end;
      end
    else
      begin
      letterArray[arrayIndex]:=letterArray[arrayIndex]+1;

      if letterArray[arrayIndex]=charLayer then
        begin
        letterArray[arrayIndex]:=-1;
        if greenmode then
          begin
          charLengths[arrayIndex]:=random(20)+14;
          end;
        end;
      end;
    end;

  for currentCharLayer:=0 to charLayer do
    begin
    setColor(black);
    for y:=currentCharLayer*charHeight to currentCharLayer*charHeight+charHeight-1 do
      begin
      line(0,y,2000,y);
      end;

    for x:=0 to 120 do
      begin
      if currentCharLayer=letterArray[x] then
        begin
        if greenMode then
          begin
          setcolor(green);
          end
        else
          begin
          setColor(white);
          end;

        outTextXY(x*charWidth+2,currentCharLayer*charHeight,#178);
        end;

      if (currentCharLayer<letterArray[x]) AND (letterArray[x]-currentCharLayer<charLengths[x]) then
        begin
        if greenmode then
          begin
          setcolor(green);
          end
        else
          begin
          setColor(32-letterArray[x]+currentCharLayer);
          end;

        outTextXY(x*charWidth+2,currentCharLayer*charHeight,chr(random(94)+32));
        end;
      end;
    end;

  delay(100);
  end;
end.
