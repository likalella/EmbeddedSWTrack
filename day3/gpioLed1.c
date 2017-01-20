#include <stdio.h>
#include <wiringPi.h>

#define LED1 3
#define LED2 12 


#define EXIT_SUCC 0
#define EXIT_FAIL 1

int main(void)
{
	int i=0;
	if(wiringPiSetupGpio() == -1)
		return EXIT_FAIL;
	
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);	
	while(i<10){
		digitalWrite(LED1, 1);
		delay(50);
		digitalWrite(LED1, 0);
		delay(50);
		i++;
	}

	for(i=0; i<5; i++){
		digitalWrite(LED2, 1);
		delay(100);
		digitalWrite(LED2, 0);
		delay(100);
	}
	
	return EXIT_SUCC;
}
