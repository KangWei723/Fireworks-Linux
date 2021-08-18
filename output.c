/*KangWei Lim*/
/* This file contains the functions that draw the fireworks and print the table */
#include "bitShifting.h"
#include "libfire.h"
#include "posVelTime.h"
#include "time.h"
#include <stdio.h>

/*GRAPHICS mode*/
/* This function will print the effect of the fireworks on the sky, fw_star, fw_bang, and fw_flash is used */
void boom (double x, double y, int hex32)
{

	int effect1Code = effect1(hex32);
	int effect2Code = effect2(hex32);
	int effect3Code = effect3(hex32);
	int colorCode = color(hex32);

	if(effect1Code)
	{
		fw_star(colorCode, x, y);
	}
	if(effect2Code)
	{
		fw_flash();
	}
	if(effect3Code)
	{
		fw_bang();
	}
	fw_refresh();
}

/* Make the programe to wait for milliseconds */
void wait (double dt)
{
	int milliSec = convertSec(dt);
	millisleep(milliSec);
}

/* This function is called when the firewors fade and the loop will run 2 seconds */
void fade (double dt)
{
	double  waitDt = dt;
	double twoSec = 2.0;

	while(waitDt < twoSec )
	{
		fw_clear();
		fw_refresh();
		wait(dt);
		waitDt = waitDt + dt; 
	}	
}

/* This function will draw the path of the fireworks: fw_dot is used */
void draw(double xPos, double xVel, double yVel, double fuseDur, int hex32)
{
	double yPos = 0.0;
	double dt = 0.0;
	int colorCode = color(hex32);	
	
	dt = calDT(yVel);	
	
	fw_clear();
	/*The path of the firework*/
	while(fuseDur > 0)
	{
		fw_dot(colorCode, xPos, yPos);
		
		yVel = calYVel(yVel, dt);
		xPos = calXPos(xPos, dt, xVel);
		yPos = calYPos(yPos, dt, yVel);
		fw_refresh();
		wait(dt);
		fuseDur = fuseDur - dt;
	}
	boom(xPos, yPos, hex32);
	wait(dt);
	fade(dt);
} 

/* TEXT mode */
/* This function is used to print the fireworks' effect location */
void effectPos(int colorNum, double xPos, double yPos, int hex32)
{	

	int effect1Code = effect1(hex32);
	int effect2Code = effect2(hex32);
	int effect3Code = effect3(hex32);

	if(effect1Code)
	{
		printf("Color #%d starburst at (%.2lf, %.2lf)'\n", colorNum, xPos, yPos);
	}
	if(effect2Code)
	{
		printf("Flash at (%.2lf, %.2lf)'\n", xPos, yPos);
	}
	if(effect3Code)
	{
		printf("Boom at (%.2lf, %.2lf)'\n", xPos, yPos);
	}
}

/* This function is called when the y velocity became negative and safety warning is printed out */
void safetyChecking (int hex32, double yVel, double fuseDur, double dt)
{
	double newYVel = calYVel(yVel, dt);
	double multiply = newYVel * yVel;
		
	if(multiply < 0)
	{
		printf("RANGE SAFETY WARNING: %x is falling at 200' alt and %.1lf' downrange with %.3lf till detonation.\n", hex32, yVel, fuseDur); 
	}
}

/* This function is called when the fireworks hit the ground (y < 0) then the safety warning is printed out */
void impactGround (double launchTime ,int hex32, double xPos, double yPos, double fuseDur)
{
	if(yPos < 0){
		int month32 = month(hex32);
		int day32 = day(hex32);
		int year32 = year(hex32);
		printf("RANGE SAFETY WARNING: At %.3lf sec %x (made on %d-%d-%d) impacts at (%.2lf, %.2lf)' with %.3lf remaining\n", launchTime, hex32, month32, day32, year32, xPos, yPos, fuseDur);
	}
}

/* This function will return 0 to the fuseDur to stop the loop when the y position is less than 0 */
double checkPosY (double yPos, double totalFuseDur)
{
	if(yPos < 0)
	{
		totalFuseDur = 0;
	}
	return totalFuseDur;
}

/* This function is the header for the TEXT mode */
void textHeader(int hex32, double dt)
{
	dt = dt * 1000;
	printf("Lab 2 starting %x with dt = %.3lf ms.\n\n", hex32, dt);
	printf(" E.T sec  (       x,      y), (      vx,     vy) fps Fuse sec\n");
}

/* This function is the data for the TEXT mode */
void textData(double launchTime, double fuseDur, double xPos, double xVel, double yVel, double dt, int colorNum, int hex32)
{
	double yPos = 0.0;
	double totalFuseDur = fuseDur;

	while(launchTime < totalFuseDur)
	{	
		printf("%5.3lf sec (  %5.2lf,  %5.2lf), (  %5.2lf,  %5.2lf) fps %5.3lf sec\n", launchTime, xPos, yPos, xVel, yVel, fuseDur);
		fuseDur = fuseDur - dt;
		launchTime = launchTime + dt;
		safetyChecking(hex32, yVel, fuseDur, dt);	
		yVel = calYVel(yVel, dt);
		xPos = calXPos(xPos, dt, xVel);
		yPos = calYPos(yPos, dt, yVel);
		totalFuseDur = checkPosY(yPos, totalFuseDur);
		impactGround(launchTime, hex32, xPos, yPos, fuseDur);
	}
	effectPos(colorNum, xPos, yPos, hex32);
	printf("\n");
}


