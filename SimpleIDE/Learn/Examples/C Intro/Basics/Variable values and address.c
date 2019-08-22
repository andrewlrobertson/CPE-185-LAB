/*

 Variable Value and Address.c

 Display a variable’s value and its address.

*/

#include "simpletools.h"                         // Include simpletools library

char array[5] = {'A','B','C','D','E'};                              // Declare/initialize variable

int main()                                       // Main function

{

 print("array start address   = %d \n\n",  array);  // Display variable value
 
for(int i = 0; i<5; i++){
 print("array[%d]   = %c \n",i, array[i]);  // Display variable value
 print("&array[%d]   = %d \n",i, &array[i]);  // Display variable value
}  

}