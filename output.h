/* KangWei Lim */
/* A header file for output.c */

void draw (double xPos, double xVel, double yVel, double fuseDur, int hex32);
void boom (int color, double, double y, int effect1, int effect2, int effect3); 
void wait (double dt);
void fade (double dt);
void safetyChecking (int hex32, double yVel, double fusDur, double dt);
void impactGround (double launchTime, int hex32, double xPos, double yPos, double fuseDur);
double checkPosY (double yPos, double totalFuseDur);
void effectPos (int colorNum, double xPos, double yPos, int hex32);
void textHeader (int hex32, double dt);
void textData (double launchTime, double fuseDur, double xPos, double xVel,  double yVel, double dt, int colorNum, int hex32);
