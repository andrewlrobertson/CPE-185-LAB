/*
  Count to Ten.c

  Version 0.94 for use with SimpleIDE 9.40 and its Simple Libraries
  
  http://learn.parallax.com/propeller-c-start-simple/counting-loops
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  int n = 0;
  for(n; n <= 200; n+=5)                // Count to ten
  {
    print("n = %d\n", n);                     // Display name & value of n
    pause(50);                               // 0.5 s between reps
  }
  n-=5;
  for(n; n > 0; n-=10)                // Count to ten
  {
    print("n = %d\n", n);                     // Display name & value of n
    pause(50);                               // 0.5 s between reps
  }
  print("All done!");                         // Display all done
}
