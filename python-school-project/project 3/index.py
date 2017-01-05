# Detects edges.
# Usage: "python index.py blockSize m a", where:
# - blockSize is width and height of one block in pixels
# - m, a: each pixel must be "brighter" than 'm' * average block noisiness
#   + 'a' to be considered an edge. The names are short for "multiplier" and
#   "addend"
#
# default: "python index.py 20 1.7 8"

from PIL import Image
from math import ceil
from sys import argv

blockSize = int(argv[1]) if len(argv) > 1 else 20

# See the first comment
m = float(argv[2]) if len(argv) > 2 else 1.7
a = int(argv[3]) if len(argv) > 3 else 8

def lerp(val1, val2, dist):
  return val1 + (val2 - val1) * dist

def processImage(path):
  image = Image.open(path)
  
  pixels = image.getdata();
  pixelsNew = [None] * ((image.width - 1) * (image.height - 1))
  
  numOfBlocksX = ceil(image.width / blockSize)
  numOfBlocksY = ceil(image.height / blockSize)
  
  # Average noisiness for each block + one layer of blocks so every real
  # block has a neighbor (a weighted average of four blocks will be used)
  avgDiff = [[0] * (numOfBlocksY + 2) for x in range(numOfBlocksX + 2)]
  
  # For every block
  for blockX in range(numOfBlocksX):
    for blockY in range(numOfBlocksY):
      minX = blockX * blockSize
      maxX = min(image.width - 1, (blockX + 1) * blockSize)
      
      minY = blockY * blockSize
      maxY = min(image.height - 1, (blockY + 1) * blockSize)
      
      # For every pixel in this block
      for x in range(minX, maxX):
        for y in range(minY, maxY):
          # Four pixels
          p1 = pixels[x + y * image.width]
          p2 = pixels[x + 1 + y * image.width]
          p3 = pixels[x + (y + 1) * image.width]
          p4 = pixels[x + 1 + (y + 1) * image.width]
          
          # Average of RGB.
          p1 = (p1[0] + p1[1] + p1[2]) / 3
          p2 = (p2[0] + p2[1] + p2[2]) / 3
          p3 = (p3[0] + p3[1] + p3[2]) / 3
          p4 = (p4[0] + p4[1] + p4[2]) / 3
          
          # Average value of four pixels
          avg = (p1 + p2 + p3 + p4) / 4
          
          # Sum of absolute values of (pixel values minus 'avg')
          avg = abs(p1-avg) + abs(p2-avg) + abs(p3-avg) + abs(p4-avg)
          
          avgDiff[blockX + 1][blockY + 1] += avg;
          
          pixelsNew[x + y * (image.width - 1)] = avg
      
      avgDiff[blockX + 1][blockY + 1] /= (maxX - minX) * (maxY - minY) or 1
  
  # Fill fake blocks
  for blockX in range(numOfBlocksX):
    avgDiff[blockX + 1][0] = avgDiff[blockX + 1][1]
    avgDiff[blockX + 1][numOfBlocksY + 1] = avgDiff[blockX + 1][numOfBlocksY]
  
  for blockY in range(numOfBlocksY + 2):
    avgDiff[0][blockY] = avgDiff[1][blockY]
    avgDiff[numOfBlocksX + 1][blockY] = avgDiff[numOfBlocksX][blockY]
  
  # Compute actual color for each pixel
  for x in range(image.width - 1):
    for y in range(image.height - 1):
      # Blocks are shifted by half of 'blockSize' because interpolation of
      # 'avgDiff' between four blocks will be used and every block should use
      # its 'avgDiff' the most in its middle.
      blockX = (x + blockSize // 2) / blockSize
      distX = blockX % 1
      blockX = int(blockX)
      
      blockY = (y + blockSize // 2) / blockSize
      distY = blockY % 1
      blockY = int(blockY)
      
      index = x + y * (image.width - 1)
      
      # Find weighted average of average noisiness of four blocks.
      limitX1 = lerp(avgDiff[blockX][blockY], avgDiff[blockX + 1][blockY], distX)
      limitX2 = lerp(avgDiff[blockX][blockY + 1],
            avgDiff[blockX + 1][blockY + 1], distX)
      
      limit = lerp(limitX1, limitX2, distY) * m + a
      
      pixelsNew[index] = (
            (255, 255, 255) if pixelsNew[index] > limit else (0, 0, 0))
  
  image = Image.new("RGB", (image.width - 1, image.height - 1))
  image.putdata(pixelsNew)
  
  return image

for i in [("0.jpg", "0"), ("1.jpg", "1"), ("2.png", "2"), ("3.jpg", "3")]:
  image = processImage("original images/image" + i[0])
  image.save("processed images/image" + i[1] + ".png")