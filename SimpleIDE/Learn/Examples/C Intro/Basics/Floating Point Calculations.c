/*
  Floating Point Calculations.c
  
  Calculate and display circumference of a circle of radius = 1.0.
  
  http://learn.parallax.com/propeller-c-start-simple/floating-point-math
*/

#include "simpletools.h"                      // Include simpletools
#include "math.h"

int main()                                    // main function
{
  float r = 3.0;                              // Set radius to 1.0
  print("Radius = %f\n",r);
  float c = 2.0 * PI * r;                     // Calculate circumference
  print("circumference = %f \n", c);          // Display circumference
  float a = PI * r * r;
  print("area = %f \n", a);
  float v = (4.0/3.0)* PI * pow(r, 3);
  print("volume = %f \n", v);
}
