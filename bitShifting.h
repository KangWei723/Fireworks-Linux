/* KangWei Lim */
/*This is a header file for bitShifting.c */

#define COLOR 4
#define DAY 8
#define EFFECT 1
#define MONTH 4
#define YEAR 12

#define COLORPOS 24
#define DAYPOS 16
#define EFFECTPOS1 31
#define EFFECTPOS2 30
#define EFFECTPOS3 29
#define MONTHPOS 12

int color ( int hexValue );
int day ( int hexValue );
int effect1 ( int hexValue );
int effect2 ( int hexValue );
int effect3 ( int hexValue );
unsigned int masking ( unsigned int mask, int constant );
int month ( int hexValue );
int year ( int hexValue );

