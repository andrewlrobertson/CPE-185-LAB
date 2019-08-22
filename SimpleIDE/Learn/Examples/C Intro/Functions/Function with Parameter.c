/*
  Function with Parameter.c
  
  Call a function that displays a value passed to it with a parameter.
  
  http://learn.parallax.com/propeller-c-functions/function-parameter
*/

#include "simpletools.h"                      // Include simpletools

void value(int a);                            // Function prototype

int main()                                    // main function
{
  counter(10, 20, 2);
}

void counter(int startVal, int endVal, int incVal)
{
  print("Count starting at: %d\n", startVal);
  for(int i = startVal; i<= endVal; i += incVal)
  {
    print("%d\n", i);
  }    
}  