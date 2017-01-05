# This the simplest and formely my most succesful implementation of edge detection.
# Usage: "python simple.py n", where n is optional number between 0 and 255,
# if present, all pixels with brightness below that will be painted black, all
# other white.

from PIL import Image
from math import ceil
from sys import argv

limit = int(argv[1]) if len(argv) > 1 else None

def processImage(path):
  image = Image.open(path)
  
  pixels = image.getdata();
  
  pixelsNew = [None] * ((image.width - 1) * (image.height - 1))
  
  for x in range(image.width - 1):
    for y in range(image.height - 1):
      p1 = pixels[x + y * image.width]
      p2 = pixels[x + 1 + y * image.width]
      p3 = pixels[x + (y + 1) * image.width]
      p4 = pixels[x + 1 + (y + 1) * image.width]
      
      p1 = (p1[0] + p1[1] + p1[2]) / 3
      p2 = (p2[0] + p2[1] + p2[2]) / 3
      p3 = (p3[0] + p3[1] + p3[2]) / 3
      p4 = (p4[0] + p4[1] + p4[2]) / 3
      
      avg = (p1 + p2 + p3 + p4) / 4
      color = abs(p1-avg) + abs(p2-avg) + abs(p3-avg) + abs(p4-avg)
      
      if limit != None:
        color = 0 if color < limit else 255
      
      pixelsNew[x + y * (image.width - 1)] = (int(color),) * 3
  
  image = Image.new("RGB", (image.width - 1, image.height - 1))
  image.putdata(pixelsNew)
  
  return image

for i in range(4):
  image = processImage("original images/image" + str(i) + ".jpg")
  image.save("processed images/simple" + str(i)
        + ("-" + str(limit) if limit != None else "") + ".png")