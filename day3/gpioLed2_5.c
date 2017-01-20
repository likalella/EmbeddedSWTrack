#include <stdio.h>
#include <wiringPi.h>

#define LED1 5
#define LED2 6
#define LED3 13
#define LED4 19
#define LED5 26

#define EXIT_SUCC 0
#define EXIT_FAIL 1

int main(void)
{
	int i;
	wiringPiSetupGpio();

	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	pinMode(LED5, OUTPUT);

	digitalWrite(LED1, 0);
	digitalWrite(LED2, 0);
	digitalWrite(LED3, 0);
	digitalWrite(LED4, 0);
	digitalWrite(LED5, 0);
	
	while(1){
	delay(1000);
	for(i=0; i<5; i++){
		digitalWrite(LED1, 1);
		digitalWrite(LED2, 1);
		digitalWrite(LED3, 1);
		digitalWrite(LED4, 1);
		digitalWrite(LED5, 1);
		delay(500);
		digitalWrite(LED1, 0);
		digitalWrite(LED2, 0);
		digitalWrite(LED3, 0);
		digitalWrite(LED4, 0);
		digitalWrite(LED5, 0);
		delay(500);
	}

	digitalWrite(LED1, 1);
	delay(100);
	digitalWrite(LED1, 0);

	digitalWrite(LED2, 1);
	delay(100);
	digitalWrite(LED2, 0);

	digitalWrite(LED3, 1);
	delay(100);
	digitalWrite(LED3, 0);

	digitalWrite(LED4, 1);
	delay(100);
	digitalWrite(LED4, 0);

	digitalWrite(LED5, 1);
	delay(100);
	digitalWrite(LED5, 0);
	
	digitalWrite(LED5, 1);
	delay(100);
	digitalWrite(LED5, 0);

	digitalWrite(LED4, 1);
	delay(100);
	digitalWrite(LED4, 0);

	digitalWrite(LED3, 1);
	delay(100);
	digitalWrite(LED3, 0);

	digitalWrite(LED2, 1);
	delay(100);
	digitalWrite(LED2, 0);

	digitalWrite(LED1, 1);
	delay(100);
	digitalWrite(LED1, 0);
	}	
	return 0;
}
