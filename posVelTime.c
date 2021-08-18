/* KangWei Lim */
/*This file contains the calculation for dt, position, velocity, converting from seconds to milliseconds.*/ 

#include <stdio.h>
#include "libfire.h"
#include "posVelTime.h"

/* Calculate the dt*/ 
double calDT (double yVel)
{ 	
   	return (( 0.25 * fw_get_delta_Y() ) / yVel);
}

/* Updating X position*/
double calXPos (double xPos, double dt, double xVel)
{
	return (xPos + ( xVel * dt )); 
}

/* Updating y position */
double calYPos (double yPos, double dt, double yVel)
{
	return (yPos + (yVel * dt) + (0.5 * -1 * GRAVITY * dt * dt));	
}

/* Updating y velocity */
double calYVel (double yVel, double dt)
{
	return (yVel + ( -1 * GRAVITY * dt));
}

/* Convert seconds to milliseconds*/
int convertSec (double sec)
{
	return ((int)(sec * 1000));
}

