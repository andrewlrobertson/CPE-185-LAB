/*
  SD Minimal.side

  Create test.txt, write characters in, read back out, display. 
  
  http://learn.parallax.com/propeller-c-simple-devices/sd-card-data
*/

#include "simpletools.h"                      // Include simpletools header  
#include "adcDCpropab.h"                      // Include adcDCpropab
  

int DO = 22, CLK = 23, DI = 24, CS = 25;      // SD card pins on Propeller BOE

int main(void)                                // main function
{
  adc_init(21, 20, 19, 18);                   // CS=21, SCL=20, DO=19, DI=18
  sd_mount(DO, CLK, DI, CS);                  // Mount SD card

  FILE* fp = fopen("test.txt", "w");          // Open a file for writing
  float val;
  
  for(int i = 0 ; i < 10; i++)
  {
  val = adc_volts(2); 
  fwrite(&val, sizeof(val), 1, fp);      // Add contents to the file
  }
  
  fclose(fp);                                 // Close the file
  
  //char s[15];                                 // Buffer for characters
  fp = fopen("test.txt", "r");                // Reopen file for reading
  
    for(int i = 0 ; i < 10; i++)
  {
  fread(&val, 4, 1, fp);                        // Read 15 characters
  print("val = %f\n", val);
  }

  fclose(fp);                                 // Close the file

  //print("First 15 chars in test.txt:\n");     // Display heading
 // print("%s", s);                             // Display characters
 // print("\n");                                // With a newline at the end
}    

