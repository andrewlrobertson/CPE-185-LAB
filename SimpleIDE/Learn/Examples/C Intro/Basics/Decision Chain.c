/*
  Decision Chain.c

  Check a series of conditions, but only act on the first one that's true.
  
  http://learn.parallax.com/propeller-c-start-simple/make-several-decisions
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  int a = 10;                                 // Initialize a variable to 25
  int b = 0;                                 // Initialize b variable to 17
  print("a = %d\n", a, b);            // Print all
  if(a > b)                                   // If a > b condition is true
  {
    print("a is positive \n");                  // Then print this message
  }
  else if (a < b)                             // a > b not true? check a < b
  {
    print("a is negative \n");                  // If true, print this instead
  }  
  else                                        // Nothing else true?
  {
    print("a is zero");                      // Print this
  }
}
