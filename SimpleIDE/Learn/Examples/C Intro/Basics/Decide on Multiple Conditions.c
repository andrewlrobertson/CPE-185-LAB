/*
  Decide on Multiple Conditions.c 
  
  Make a decision based on two conditions.  
  
  http://learn.parallax.com/propeller-c-start-simple/make-complicated-decisions 
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  int a = 150;                                // Initialize a variable to 25
  int b = 100;
  int c = 200;                                 // Initialize b variable to 17
  print("a = %d\n", a, b);            // Print all
  if((a >= b) && (a <= c))                   // If a > b AND A == 100
  {
    print("a is in the 100-200 range (inclusive)\n");           // Then print this message
  }
}
