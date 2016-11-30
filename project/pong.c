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
int paddleSize=screenWidth/2;
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

AbRect rect10 = {abRectGetBounds, abRectCheck, {10,10}}; /**< 10x10 rectangle */
AbRect bar = {abRectGetBounds, abRectCheck, {15, 3}};//the bar for the paddleboad

AbRectOutline fieldOutline = {/* playing field */
  abRectOutlineGetBounds, abRectOutlineCheck,
  {screenWidth/2 - 10, screenHeight/2 - 10}
};


Layer fieldLayer = {/* playing field as a layer */
  (AbShape *) &fieldOutline,
  {screenWidth/2, screenHeight/2},/**< center */
  {0,0}, {0,0},    /* last & next pos */
  COLOR_BLACK,
};


Layer pongBar = {/**< Layer with a the pong bar black color*/
  (AbShape *)&bar,
  {paddleSize, screenHeight-30}, /**< center */
  {0,0}, {0,0},    /* last & next pos */
  COLOR_BLACK,
  &fieldLayer,
};

Layer ball = {/**< Layer with an red circle */
  (AbShape *)&circle8,
  {(screenWidth/2)+10, (screenHeight/2)+5}, /**< bit below & right of center */
  {0,0}, {0,0},    /* last & next pos */
  COLOR_RED,
  &pongBar,
};






/** Initializes everything, enables interrupts and green LED, 

 *  and handles the rendering for the screen

 */

void main()

{
  P1DIR |= GREEN_LED;/**< Green led on when CPU on */
  P1OUT |= GREEN_LED;

  configureClocks();
  lcd_init();
  shapeInit();
  p2sw_init(1);

  shapeInit();

  layerInit(&layer0);
  layerDraw(&layer0);


  layerGetBounds(&fieldLayer, &fieldFence);


  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);              /**< GIE (enable interrupts) */



}




/** Watchdog timer interrupt handler. 15 interrupts/sec */

void wdt_c_handler(){
  static short count = 0;
  P1OUT |= GREEN_LED;      /**< Green LED on when cpu on */
  count ++;
  if (count == 15) {
    mlAdvance(&ml0, &fieldFence);
    if (p2sw_read())
      redrawScreen = 1;
    count = 0;
  }
  P1OUT &= ~GREEN_LED;    /**< Green LED off when cpu off */

}
