/*
  Joystick.c

  Simple demo with the Parallax 2-axis Joystick.
*/
#include "adcDCpropab.h"                            // Include adcDCpropAB
#include "simpletools.h"                            // Include simpletools


int main()                                          // Main function
{
  adc_init(21, 20, 19, 18);                         // CS=21, SCL=20, DO=19, DI=18

  float lrV, udV;                                   // Voltage variables

  while(1)                                          // Loop repeats indefinitely
  {
    udV = adc_volts(2);                             // Check A/D 2                
    lrV = adc_volts(3);                             // Check A/D 3
   
    putChar(HOME);                                  // Cursor -> top-left "home"
    print("Up/Down = %.2f V %c\n", udV, CLREOL);    // Display voltage
    print("Left/Right = %.2f V %c\n", lrV, CLREOL); // Display voltage

    pause(100);                                     // Wait 1/10 s
  }  
}
