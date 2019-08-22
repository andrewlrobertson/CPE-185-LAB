/*
  Measure Volts.c

  Make voltmeter style measurements with the Propeller Activity Board.

  http://learn.parallax.com/propeller-c-simple-circuits/measure-volts
*/

#include "simpletools.h"                      // Include simpletools
#include "adcDCpropab.h"                      // Include adcDCpropab

int main()                                    // Main function
{
  adc_init(21, 20, 19, 18);                   // CS=21, SCL=20, DO=19, DI=18

  float v3;                               // Voltage variables

  while(1)                                    // Loop repeats indefinitely
  {               
    v3 = adc_volts(3);                        // Check A/D 3
    putChar(HOME);                            // Cursor -> top-left "home"
    print("A/D3 = %f V%c\n", v3, CLREOL);     // Display volts    
    if(v3 > 1.0)
    {
      print("***TOO HOT****");
      high(26);
      low(27);
      pause(20);
      high(27);
      low(26);
      pause(20);                               
    }
    else if (v3 < .5)
    {
      print("***TOO COLD***");
      low(27);
      low(26);
      pause(40);                                   
    }
    else
    {
      print("**Just right**");
      high(27);
      high(26);
      pause(40);                                
    }                  

  }  
}
