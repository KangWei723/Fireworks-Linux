/* KangWei Lim */
/* main function */

#include <stdio.h>
#include "libfire.h"
#include "posVelTime.h"
#include "bitShifting.h"
#include "debug.h"
#include "output.h"

int main()
{
	/* Variables for storing the input data */ 
	double launchTime, fuseDur, xPos, xVel, yVel; 
	int hex32;

	double dt = 0.0;	
	int colorNum = 0;

	/* Reading input file using scanf loop */
	while(scanf("%lf %x %lf %lf %lf %lf", &launchTime, &hex32, &fuseDur, &xPos, &xVel, &yVel) == 6 )
	{
		dt = calDT(yVel);	
		
		/*Text mode*/
		if(TEXT)
		{
			colorNum = colorNum + 1;
			textHeader (hex32, dt);	
			textData(launchTime, fuseDur, xPos, xVel, yVel, dt, colorNum, hex32);
		}
		/*Graphics mode*/
		if(GRAPHICS)
		{
			if(fw_initialize()) 
			{
				draw(xPos, xVel, yVel, fuseDur, hex32);
			}	
		}
	}
	/*It will only run when it is in Graphics mode*/
	if(GRAPHICS)
	{
		fw_teardown();
	}
	return 0;
}


	


