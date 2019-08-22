/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h"                            // Include servo header
#include "adcDCpropab.h"                            // Include adcDCpropAB

int* button_p, joystick_p, led_p, servo_p;
volatile int systemStatus, angle;  

void joystick()
{
  while(1)
  {
    angle = (adc_volts(0)/5) * 1800;
  }    
}
  
void led()
{
    while(1)
    {
      if(systemStatus)
      {
        high(26);
      }
      else
      {
        low(26);
      }                
    }      
}

void servo()
{
  while(1)
  {
    servo_angle(16, angle);
  }    
}    

void button()
{
  while(1)
  {
    if(!input(9))
    {
      if(systemStatus == 0)
      {
        joystick_p = cog_run(joystick, 128);
        servo_p = cog_run(servo, 128);
        systemStatus = 1;
        pause(200);    
      }
      else
      {
        cog_end(joystick_p);
        cog_end(servo_p);
        servo_stop();
        systemStatus = 0;
        pause(200);
      }                
    }      
  }    
}

int main()                                    // Main function
{
  adc_init(21, 20, 19, 18);                         // CS=21, SCL=20, DO=19, DI=18
  systemStatus = 1;
  joystick_p = cog_run(joystick, 128);
  led_p = cog_run(led, 128);
  servo_p = cog_run(servo, 128);
  button_p = cog_run(button, 128);
}
