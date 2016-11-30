#include <stdio.h>
#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>


#define GREEN_LED BIT6

int score;
int speed;
int paddleSize;
char scoreMessage[10] = "Score: ";
char gameOverMessage[10] ="Game Over";
int 







/*
 * Moving Layer 
 * Linked List of layer references
 * Velocity represents one iteration of change (direction & magnitude)
 *
 */

typedef struct MovLayer_s{
  Layer *layer;
  Vec velocity;
  struct MovLayer_s *next;
}MovLayer;
