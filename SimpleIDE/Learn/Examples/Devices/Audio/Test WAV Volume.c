/*
  Test WAV Volume.c

  Play back a .wav file and try a few different volume settings.   
  
  http://learn.parallax.com/propeller-c-simple-devices/play-wav-files
*/

#include "simpletools.h"
#include "wavplayer.h"
    
int main()                                        // main function
{
  int button1, button2;
  int DO = 22, CLK = 23, DI = 24, CS = 25;        // SD I/O pins
  sd_mount(DO, CLK, DI, CS);                      // Mount SD card
 
  button1 = input(7);                             //pull down externally
  button2 = input(8);                             //pull down externally
 
  const char track1[] = {"track1.wav"};       // Set up techloop string
  const char track2[] = {"track2.wav"};       // Set up techloop string
  
  if(button1)
  {
  wav_play(track1);                             // Pass to wav player
 
  wav_volume(8);
  pause(3500);

  wav_stop();                                      // Stop playing
  }
  
  else if(button2)
  {
  wav_play(track2);                             // Pass to wav player
 
  wav_volume(8);
  pause(3500);

  wav_stop();                                      // Stop playing
  }  
}