/*KangWei Lim*/
/*This file contains all the bit shifiting function */
#include "bitShifting.h"

/* This function will shift the hex code and return the first value of the binary number for the effect */  
int effect1 ( int hexValue )
{
	int i = 0;
	unsigned int mask = 0;	
	int code = 0x0;

	hexValue = code + hexValue;
	mask = masking(mask, EFFECT);	
	hexValue = hexValue >> EFFECTPOS1; 
	hexValue = hexValue & mask; 
	return hexValue;
}

/* This function will shift the hex code and return the second value of the binary number for the effect */
int effect2 (int hexValue )
{
	int i = 0;
	unsigned int mask = 0;
	int code = 0x0;
	
	hexValue = code + hexValue;
	mask = masking(mask, EFFECT);
	hexValue = hexValue >> EFFECTPOS2;
	hexValue = hexValue & mask;
	return hexValue;
}

/* This function will shift the hex code and return the third value of the binary number for the effect */
int effect3 ( int hexValue )
{
	int i = 0;
	unsigned int mask = 0;
	int code = 0x0;
	
	hexValue = code + hexValue;
	mask = masking(mask, EFFECT);
	hexValue = hexValue >> EFFECTPOS3;
	hexValue = hexValue & mask;
	return hexValue;
}

/* This function will shift the hex code and return the color code (1~7) */
int color ( int hexValue )
{
	int i = 0;
	unsigned int mask = 0;
	int code = 0x0;
	
	hexValue = code + hexValue;
	mask = masking(mask, COLOR);
	hexValue = hexValue >> COLORPOS;
	hexValue = hexValue & mask;
	return hexValue;
}

/* This function will shift the hex code and return the value: day */
int day ( int hexValue )
{
	int i = 0;
	unsigned int mask = 0;
	int code = 0x0;

	hexValue = code + hexValue;
	mask = masking(mask, DAY);
	hexValue = hexValue >> DAYPOS;
	hexValue = hexValue & mask;
	return hexValue;
}

/* This function will shift the hex code and return the value: month */
int month ( int hexValue )
{
	int i = 0;
	unsigned int mask = 0;
	int code = 0x0;

	hexValue = code + hexValue;
	mask = masking(mask, MONTH);
	hexValue = hexValue >> MONTHPOS;
	hexValue = hexValue & mask;
	return hexValue;
}

/* This function will shift the hex code and return the value: year */
int year ( int hexValue )
{
	int i = 0;
	unsigned int mask = 0;
	int code = 0x0;

	hexValue = code + hexValue;
	mask = masking(mask, YEAR);
	hexValue = hexValue & mask;
	return hexValue;
}

unsigned int masking (unsigned int mask, int constant)
{
	int i = 0;
	while ( i < constant )
	{
		mask = mask << 1; 
		mask = mask + 1;
		i++;
	}
	return mask;
} 


