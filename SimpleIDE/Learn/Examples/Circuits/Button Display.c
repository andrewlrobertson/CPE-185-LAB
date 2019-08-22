/*
  Button Display.c
  
  Dislays the state of the P3 button in the SimpleIDE Terminal.
  1 -> button pressed, 0 -> button not pressed.
  
  http://learn.parallax.com/propeller-c-simple-circuits/check-pushbuttons
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  while(1)                                    // Endless loop
  {
    int button = input(3);                    // P3 input -> button variable
    int button2 = input(4);
    print("button = %d\tbutton2 = %d\n", button, button2);           // Display button state
    
    
    if(button == 1){
      high(26);
      pause(50);
      low(26);
      pause(50);
    }
    else{
      pause(100);
    }          
    if(button2 == 1){
      high(27);
      pause(50);
      low(27);
      pause(50);
    }
    else{
      pause(100);
    }   
    pause(100);                               // Wait 0.1 second before repeat
  }
}
