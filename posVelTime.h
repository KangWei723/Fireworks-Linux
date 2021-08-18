/* KangWei Lim */
/* Header file for posVelTime.c */

#define GRAVITY 32.17405 

double calDT (double yVel);
double calXPos (double xPos, double dt, double xVel);
double calYPos (double yPos, double dt, double yVel);
double calYVel (double yVel, double dt);
int convertSec (double seconds);

