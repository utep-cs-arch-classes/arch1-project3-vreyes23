#arch1-project3-vreyes23
# Project 3: Pong Game
## Project Overview
This project uses MSP430 and the LCD Display to create a hybrid of a pong and brick breaker game. This is a single player game in which the player has a paddle which he or she bounces the ball from the top of the display while attempting to get a high score. As the game progresses the ball will be moving at a higher velocity and eventually the paddle will become smaller, hence increasing the difficulty to the player. Once the player is unable to "paddle" the ball back then the game ends and the score is revealed along with a "Game Over" screen.


## Game Instructions
These are the instructions how the game will play once it is initiated and you will see a main menu displayed on the LCD.

- BTN1- Will start the Game

Afterwards the game will be in full swing and the following controls will assist the player in moving the paddle.

- BTN1 -Will move the paddle to the left.
- BTN4 -Will move the paddle to the right.
- BTN2 -Will return you to the main menu.

## Files In This Directory
This program contains the following files:

- pong.c
- wdt_handler.s
- Makefile

##To Run The Game

- To compile:
~~~
$ make
~~~
- To load the game:
~~~
$ make load
~~~
- To remove binaries:
~~~
$ make clean
~~~

Enjoy the game!