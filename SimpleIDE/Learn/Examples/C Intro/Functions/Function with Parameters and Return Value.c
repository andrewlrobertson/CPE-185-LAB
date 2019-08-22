/*
  Function with Parameters and Return Value.c
  
  Pass parameters to a function, let it do its job, and display the result
  it returns.
  
  http://learn.parallax.com/propeller-c-functions/function-parameters-and-return
*/

#include "simpletools.h"                      // Include simpletools

int subtractor(int a, int b);                      // Function prototype

int main()                                    // main function
{
  int n = subtractor(25, 17) + subtractor(100,2);                      // Call adder function
  print("subtractor's result is = %d\n", n);         // Display adder function result
  n = subtractor(-100, 5);
  print("subtractor result = %d", n);
}

int subtractor(int a, int b)                       // adder function
{
  int c = a - b;                              // Add two values
  return c;                                   // Return the result
}
