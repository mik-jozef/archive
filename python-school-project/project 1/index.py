# Simulation of game inspired by "Clovece, nezlob se!" (Mensch ärgere Dich nicht)
# Players move along 'numOfFields' fields, the quickest wins. Unlike in the orig-
# iginal, players start at the same position. No two game pieces can occupy the
# same position, except game pieces of different players at the last four fields.
# If a player lands on other player's game piece, it moves to position zero. Each
# round, all players move one game piece along one to six fields (if they can).
# 
# Variations:
# 1. Number of players: 2 to 4
# 2. Number of fields: 10 to 99
# 3. Strategy: players move random game pieces vs always land on other players'
#    game pieces if they can.
# 
# Measured data: number of rounds til a player wins.
#
# The game is played a hundred times for each setting, that is a total of 54000
# games. You can change this with command line argument. (eg. python index.py 10)

from time import time
from random import randint
from functools import reduce
from sys import argv

import matplotlib.pyplot as plt

start = time()

gamesPerSetting = int(argv[1]) if len(argv) > 1 else 100

# Represents one match.
class Game:
  def __init__(self, numOfPlayers, numOfFields, betterStrategy):
    self.gamePieces = []
    self.numOfFields = numOfFields
    self.betterStrategy = betterStrategy
    self.players = [Player(self) for f in range(numOfPlayers)]
  
  def addGamePiece(self, gamePiece):
    self.gamePieces.append(gamePiece)
  
  # Executes the game and returns the number of rounds.
  def play(self):
    numOfRounds = 1
    
    # While no one won.
    while not reduce(lambda x, y: x or y.move(), self.players, False):
      numOfRounds += 1
    
    return numOfRounds

class Player:
  def __init__(self, game):
    self.game = game
    self.gamePieces = [GamePiece(game, self) for f in range(4)]
  
  # Moves a game piece of this player, returns true if he won.
  def move(self):
    howMuch = randint(1, 6)
    movablePieces = [x for x in self.gamePieces if x.canMove(howMuch)]
    
    if self.game.betterStrategy:
      betterPieces = [x for x in movablePieces
            if x.canLandOnAnotherPlayer(howMuch)]
      
      if len(betterPieces) > 0:
        movablePieces = betterPieces
    
    if len(movablePieces) > 0:
      movablePieces[randint(0, len(movablePieces) - 1)].move(howMuch)
    
    for piece in self.gamePieces:
      if piece.position < self.game.numOfFields - 4:
        return False
    
    return True

class GamePiece:
  def __init__(self, game, player):
    game.addGamePiece(self)
    
    self.position = 0
    self.game = game
    self.player = player
  
  def canMove(self, howMuch):
    newPosition = howMuch + self.position
    
    if newPosition >= self.game.numOfFields:
      return False
    
    for piece in self.player.gamePieces:
      if piece.position == newPosition:
        return False
    
    return True
  
  def canLandOnAnotherPlayer(self, howMuch):
    for piece in self.game.gamePieces:
      if (piece.position == self.position + howMuch
            and piece.player != self.player
            and piece.position < self.game.numOfFields - 4):
        return True
    
    return False
  
  # Moves itself and potentially returns another game piece to start.
  def move(self, num):
    self.position += num
    
    for piece in self.game.gamePieces:
      if (piece.position == self.position and piece.player != self.player
            and piece.position < self.game.numOfFields - 4):
        piece.startAnew()
        break
  
  def startAnew(self):
    self.position = 0

data = []

n = 0 # Number of games played per unique setting.

for numOfPlayers in range(2, 5):
  for betterStrategy in [False, True]:
    arr1, arr2 = [], []
    
    # numOfPlayers, betterStrategy, x, y, label
    data.append((numOfPlayers, betterStrategy, arr1, arr2,
          str(numOfPlayers) + (" smart" if betterStrategy else " dumb") + " players"))
    
    for numOfFields in range(10, 100):
      sum = 0
      n += 1
      
      for f in range(gamesPerSetting):
        sum += Game(numOfPlayers, numOfFields, betterStrategy).play()
      
      arr1.append(numOfFields)
      arr2.append(sum / gamesPerSetting)
      
      print("\r" + str(n) + "/540", end="          ")

print("\nElapsed time: " + str(time() - start) + " seconds.")

for setting in data:
  plt.plot(setting[2], setting[3], label=setting[4])

plt.xlabel("Length of game board")
plt.ylabel("Number of rounds til someone wins")
plt.legend(loc=2)
plt.show()