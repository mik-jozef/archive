# My first implementation seems to be correct, but it's extremely slow. Maybe
# it's just because of the number of games played, but I'll try to make something
# faster anyway.
# Update: this is almost equaly fast (a bit slower, actually). I guess simulating
# 54000 games is bound to take some time...
# This is NOT part of any of my projects anymore, but should be equivalent to
# project 1.

from time import time
from sys import argv
from random import randint

import matplotlib.pyplot as plt

start = time()

gamesPerSetting = int(argv[1]) if len(argv) > 1 else 100

n = 0 # Number of games played per unique setting.

data = []

for numOfPlayers in range(2, 5):
  for betterStrategy in [False, True]:
    arr1, arr2 = [], []
    data.append((numOfPlayers, betterStrategy, arr1, arr2))
    
    for numOfFields in range(10, 100):
      n += 1
      round = 1
      
      for f0 in range(gamesPerSetting):
        someoneWon = False
        
        game = [[0 for f1 in range(4)] for f0 in range(4)]
        
        while (not someoneWon):
          round += 1
          
          for player in range(numOfPlayers):
            player = game[player]
            
            move = randint(1, 6)
            
            movablePieces = [i for i in range(4)
                  if move + player[i] < numOfFields and move + player[i] not in player]
            
            if betterStrategy:
              betterPieces = [i for i in movablePieces
                    if any([player[i] + move in otherPlayer for otherPlayer in game
                          if otherPlayer != player
                                and player[i] + move < numOfFields - 4])]
              
              if len(betterPieces) > 0:
                movablePieces = betterPieces
            
            if len(movablePieces) > 0:
              index = movablePieces[randint(0, len(movablePieces) - 1)]
              
              player[index] += move
              
              if player[index] < numOfFields - 4:
                breakVar = False
                
                for otherPlayer in game:
                  if breakVar:
                    break
                  
                  if player == otherPlayer:
                    continue
                  
                  for i in range(4):
                    if otherPlayer[i] == player[index]:
                      otherPlayer[i] = 0
                      breakVar = True
                      break
              
              for gamePiece in player:
                if gamePiece < numOfFields - 4:
                  break
              else:
                someoneWon = True
                break
      
      arr1.append(numOfFields)
      arr2.append(round / gamesPerSetting)
      
      print("\r" + str(n) + "/" + str(540), end="          ")

print("\nElapsed time: " + str(time() - start) + " seconds.")

for setting in data:
  plt.plot(setting[2], setting[3])

plt.show()
