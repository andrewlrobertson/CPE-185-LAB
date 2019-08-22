/*
  Cog Info Exchange.c
 
  Example of two cogs exchanging information with a volatile global variable.
  The main function in cog 0 changes the value; and it affects the blink function's
  rate running in cog 1.

  http://learn.parallax.com/multicore-approaches/cores-sharing-data
*/

#include "simpletools.h"                      // Library include

void blink();                                 // Forward declaration
void blink2();
int *cog;                                     // For storing process ID
int * cog2;
volatile int dt;                              // Declare dt for both cogs
volatile int reps;
volatile int reps2;

int main()                                    // Main function
{
  dt = 100;                                   // Set value of dt to 100
  cog = cog_run(blink, 128);                  // Run blink in other cog
  cog2 = cog_run(blink2, 128);
  pause(2000);                                // Let run for 2 s
  print("reps = %d \n", reps);
  print("reps2 = %d \n", reps2);

  dt = 50;                                    // Update value of dt
  pause(2000);                                // New rate for 2 s
  print("reps = %d \n", reps);
  print("reps2 = %d \n", reps2);
  cog_end(cog);                               // Stop the cog
  cog_end(cog2);
}

void blink()                                  // Function for other cog
{
  while(1)                                    // Endless loop
  {
    reps++;
    high(26);                                 // LED on
    pause(dt);                                // ...for dt ms
    low(26);                                  // LED off
    pause(dt);                                // ...for dt ms
  }
}

void blink2()                                  // Function for other cog
{
  while(1)                                    // Endless loop
  {
    reps2++;
    high(27);                                 // LED on
    pause(dt*2);                                // ...for dt ms
    low(27);                                  // LED off
    pause(dt*2);                                // ...for dt ms
  }
}