/*
Scan to Int.c
*/

#include "simpletools.h"                         // Include simpletools library

int startVal;                                        // Declare variable named reps
int endVal;

int main()                                       // Main function
{
  putStr("Enter values to start and end with \n");
  putStr("Pressing enter after each one.\n ");

  startVal = getDec();
  endVal = getDec();
  putStr("\nCounting from ");
  putDec(startVal);
  putStr(" to ");
  putDec(endVal);
  putStr(".\n");

  for(int n = startVal; n <= endVal; n++)                 // Count to value scanned
  {
  putStr("i = ");
  putDec(n);
  putStr(".\n");    
  }

  putStr("Done!\n ");
}
