/*
  Get Text.c
*/

#include "simpletools.h"                      // Include simpletools library

char text[16];                                // Declare character array
char pass[9] = {"password"};

int main()                                    // Main function
{
  print("Enter password: ");                 // User prompt

  for(int i = 0;i < 16; i++)
  {
    text[i] = getChar();
    putChar('*');
    if((text[i] == '\r') || (text[i] == '\n'))
    {
      putChar('\n');
      text[i] = 0;
      break;
    }      
  }    
  
  if(!strcmp(pass, text))
  {
    print("pass does match text\n");
  }
  else
  {
    print("pass does NOT match text\n");    
  }        
}