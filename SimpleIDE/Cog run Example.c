/*
Cog Run Example.c
*/
#include "simpletools.h" // Library include
void blink(); // Forward declaration
int main() // Main function
{
int *cog = cog_run(&blink, 10); // Run blink in other cog
pause(3000); // ...for 3 seconds
cog_end(cog); // then stop the cog
}
void blink() // Blink function for other cog
{
while(1) // Endless loop for other cog
{
high(26); // P26 LED on
pause(100); // ...for 0.1 seconds
low(26); // P26 LED off
pause(100); // ...for 0.1 seconds
}
}
void blink2() // Blink function for other cog
{
while(1) // Endless loop for other cog
{
high(26); // P26 LED on
pause(100); // ...for 0.1 seconds
low(26); // P26 LED off
pause(100); // ...for 0.1 seconds
}
}