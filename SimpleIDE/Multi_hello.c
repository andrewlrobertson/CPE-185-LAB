/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools

void hello(void);

int main()                                    // Main function
{
  // Add startup code here.
  print("In Main \n\n");
  for(int i = 0; i<4; i++)
  {
    hello();
  }    
  print("Back in main\n");
      
}

  void hello(void)
  {
    print("In hello function \n\n");
  }