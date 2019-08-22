/*
  Cog Run Example.c
  
  Run function that blinks a light with another cog continuously.

  http://learn.parallax.com/multicore-approaches/simple-multicore
*/

#include "simpletools.h"                      // Library include

void blink();                                 // Forward declaration

void blink2()                                  // Blink function for other cog
{
  while(1)                                    // Endless loop for other cog
  {
    high(27);                                 // P26 LED on
    pause(223);                               // ...for 0.1 seconds
    low(27);                                  // P26 LED off
    pause(223);                               // ...for 0.1 seconds
  }
}



int main()                                    // Main function
{
  cog_run(blink, 128);                        // Run blink in other cog
  cog_run(blink2, 128);                        // Run blink in other cog
}

void blink()                                  // Blink function for other cog
{
  while(1)                                    // Endless loop for other cog
  {
    high(26);                                 // P26 LED on
    pause(100);                               // ...for 0.1 seconds
    low(26);                                  // P26 LED off
    pause(100);                               // ...for 0.1 seconds
  }
}

  