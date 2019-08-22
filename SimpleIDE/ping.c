/*
  Test Ping Distance.c
 
  Measure and display Ping))) Ultrasonic Distance Sensor distance measurements.
*/

#include "simpletools.h"                      // Include simpletools header
#include "ping.h"                             // Include ping header

int main()                                    // Main function
{
  while(1)                                    // Repeat indefinitely
  {
    int cmDist = ping_cm(15);                 // Get cm distance from Ping)))
    print("cmDist = %d\n", cmDist);           // Display distance
    pause(200);                               // Wait 1/5 second
  }
}

