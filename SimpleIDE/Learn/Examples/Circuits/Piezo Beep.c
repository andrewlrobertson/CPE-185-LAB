/*
  Piezo Beep.c

  Beep a piezo speaker connected to Propeller I/O pin P4.
  
  http://learn.parallax.com/propeller-c-simple-circuits/piezo-beep
*/

#include "simpletools.h"                      // Include simpletools                   

int note[] = {1174.7,1174.7,1108.7,1108.7,
              1046.5,1046.5,1108.7,1108.7, 1174.7, 1174.7};
int main()                                    // main function             
{
  for (int i = 0; i < (sizeof(note)/sizeof(int)); i++)
  {
  if(i==8)
  {
  freqout(4, 100, note[i]);                     // pin, duration, frequency
  pause(210);
  }
  else if(i==9)
  {
  freqout(4, 700, note[i]);                     // pin, duration, frequency
  pause(10);
  }
  else
  {        
  freqout(4, 300, note[i]);                     // pin, duration, frequency
  pause(10);
  }  
  }  
}
