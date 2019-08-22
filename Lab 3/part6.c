#include <stdio.h> // Used for printf() statements
#include <wiringPi.h> // Include WiringPi library!
// Pin number declarations. We're using the Broadcom chip pin numbers.
const int segA = 13, segB = 6, segC = 16, segD = 20, segE = 21,
	  segF = 19, segG = 26, segDP = 12;
int counter = 0;

void interrupt()
{
counter = 0;
}

void display(int number)
{
	switch(number)
	{
	case 0:
		digitalWrite(segA, 1);
                digitalWrite(segB, 1);
                digitalWrite(segC, 1);
                digitalWrite(segD, 1);
                digitalWrite(segE, 1);
                digitalWrite(segF, 1);
                digitalWrite(segG, 0);
                digitalWrite(segDP, 0);
		break;
        case 1:
                digitalWrite(segA, 0);
                digitalWrite(segB, 1);
                digitalWrite(segC, 1);
                digitalWrite(segD, 0);
                digitalWrite(segE, 0);
                digitalWrite(segF, 0);
                digitalWrite(segG, 0);
                digitalWrite(segDP, 0);
		break;
        case 2:
                digitalWrite(segA, 1);
                digitalWrite(segB, 1);
                digitalWrite(segC, 0);
                digitalWrite(segD, 1);
                digitalWrite(segE, 1);
                digitalWrite(segF, 0);
                digitalWrite(segG, 1);
                digitalWrite(segDP, 0);
		break;
        case 3:
                digitalWrite(segA, 1);
                digitalWrite(segB, 1);
                digitalWrite(segC, 1);
                digitalWrite(segD, 1);
                digitalWrite(segE, 0);
                digitalWrite(segF, 0);
                digitalWrite(segG, 1);
                digitalWrite(segDP, 0);
		break;
        case 4:
                digitalWrite(segA, 0);
                digitalWrite(segB, 1);
                digitalWrite(segC, 1);
                digitalWrite(segD, 0);
                digitalWrite(segE, 0);
                digitalWrite(segF, 1);
                digitalWrite(segG, 1);
                digitalWrite(segDP, 0);
		break;
        case 5:
                digitalWrite(segA, 1);
                digitalWrite(segB, 0);
                digitalWrite(segC, 1);
                digitalWrite(segD, 1);
                digitalWrite(segE, 0);
                digitalWrite(segF, 1);
                digitalWrite(segG, 1);
                digitalWrite(segDP, 0);
		break;
        case 6:
                digitalWrite(segA, 1);
                digitalWrite(segB, 0);
                digitalWrite(segC, 1);
                digitalWrite(segD, 1);
                digitalWrite(segE, 1);
                digitalWrite(segF, 1);
                digitalWrite(segG, 1);
                digitalWrite(segDP, 0);
		break;
        case 7:
                digitalWrite(segA, 1);
                digitalWrite(segB, 1);
                digitalWrite(segC, 1);
                digitalWrite(segD, 0);
                digitalWrite(segE, 0);
                digitalWrite(segF, 0);
                digitalWrite(segG, 0);
                digitalWrite(segDP, 0);
		break;
        case 8:
                digitalWrite(segA, 1);
                digitalWrite(segB, 1);
                digitalWrite(segC, 1);
                digitalWrite(segD, 1);
                digitalWrite(segE, 1);
                digitalWrite(segF, 1);
                digitalWrite(segG, 1);
                digitalWrite(segDP, 0);
		break;
        case 9:
                digitalWrite(segA, 1);
                digitalWrite(segB, 1);
                digitalWrite(segC, 1);
                digitalWrite(segD, 1);
                digitalWrite(segE, 0);
                digitalWrite(segF, 1);
                digitalWrite(segG, 1);
                digitalWrite(segDP, 0);
		break;
	}
	return;
}

int main(void)
{

	// Setup stuff:
	wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers
	pinMode(segA, OUTPUT); // Set regular LED as output
        pinMode(segB, OUTPUT); // Set regular LED as output
        pinMode(segC, OUTPUT); // Set regular LED as output
        pinMode(segD, OUTPUT); // Set regular LED as output
        pinMode(segE, OUTPUT); // Set regular LED as output
        pinMode(segF, OUTPUT); // Set regular LED as output
        pinMode(segG, OUTPUT); // Set regular LED as output
        pinMode(segDP, OUTPUT); // Set regular LED as output

	wiringPiISR(18, INT_EDGE_RISING, &interrupt);

	printf("C GPIO program running! Press CTRL+C to quit.\n");
	while(1)
	{
                display(counter);
		counter = counter + 1;
		if (counter == 10)
		{
			counter = 0;
		}
		delay(500);
	}
	return 0;
}
