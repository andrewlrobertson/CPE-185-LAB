/*
  Global Exchange.c
  
  Functions exchange information with global variables. 
  
  http://learn.parallax.com/propeller-c-functions/memory-functions-can-share
*/

#include "simpletools.h"                      // Include simpletools

void subtracter(void);                             // Forward declaration

int a, b, n;                                  // Global variables

int main()                                    // main function
{
  a = 96;                                     // Set values of a & b
  b = 32;
  subtracter();                                    // Call adder function
  print("n = %d\n", n);                       // Display result
}

void subtracter(void)                              // Adder, no parameters or return
{
  n = a - b;                                  // Use values of a & b to set n
}
