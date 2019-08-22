/*
  Seven Segment.c
  
  Display digits on a 7 segment (common cathode) LED display.
  
  http://learn.parallax.com/propeller-c-simple-circuits/seven-segment-display
*/

#include "adcDCpropab.h"                      // Include adcDCpropab
#include "simpletools.h"                      // Include simpletools
#include "math.h"

float v2, v3;                               // Voltage variables
float diff;
int int_diff;

int n[] = {0b11100111,0b10000100,0b11010011,0b11010110,
           0b10110100,0b01110110,0b01110111,0b11000100,
           0b11110111,0b11110110}; 

int main()                                    // main function
{
  adc_init(21, 20, 19, 18);                   // CS=21, SCL=20, DO=19, DI=18
  set_directions(15, 8, 0b11111111);          // P15...P8 -> output
  pause(1000);                                              

while(1)                                    // Loop repeats indefinitely
{
  v2 = adc_volts(2);
  v3 = adc_volts(3);
  diff = v3-v2;
  int_diff = diff + .5;
  putChar(HOME);                            // Cursor -> top-left "home"
  print("Voltage = %f V%c\n", diff, CLREOL);     // Display volts
  set_outputs(15, 8, n[int_diff] );             // 0-9
  print("n[%d] displayed.\n", int_diff);       
  pause(100);
}

}
