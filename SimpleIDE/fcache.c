#include "simpletools.h"

#define POS_EDGE_CTR 0b01010 << 26;           // Pos edge counter config val

void pinToggle(void *par);                    // Function prototype

volatile int dt, n, pin;                      // Shared between cogs
unsigned int stack[43 + 128];                 // Large stack - prototyping

int main()                                    // Main function
{
  pin = 5;
  //dt = CLKFREQ/10;                            // Set toggle interval

  cogstart(pinToggle, NULL,                   // Pin toggle process to other cog  
           stack, sizeof(stack));
           
  FRQA = 1;                                   // PHSA+1 for each pos edge                              
  CTRA = pin | POS_EDGE_CTR;                  // CTRA pos edge count on P5
  int dtm = CLKFREQ;                          // Time increment for main
  int t   = CNT;                              // Capture current tick count

  while(1)                                    // Main loop
  {
    PHSA = 0;                                 // Clear phase accumulator
    waitcnt(t += dtm);                        // Wait 1 s
    int cycles = PHSA;                        // Capture cycle count
    print("n = %d, ", n);                     // Display n
    print("cycles = %d\n", cycles);           // Display cycles counted
  }    
}

__attribute__((fcache))                        // Cache this function in cog
void pinToggle(void *par)                      // pinToggle function
{
  int pmask = 1 << pin;                        // Set up pin mask
  DIRA |= pmask;                               // Pin to output
  //int t = CNT;                                 // Capture current time
  while(1)                                     // Main loop in cog
  {
    //n++;                                       // Keep a running count
    OUTA ^= pmask;                             // Toggle output
    //waitcnt(t+=dt);                            // Interval gate
  }                            
}
