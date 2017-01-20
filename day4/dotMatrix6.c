#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <stdint.h>

#define SDATA		6
#define STR_CLK		13
#define SHR_CLK 	19
#define SHR_CLEAR	26

void allclear(void);

void init(void)
{
	if(wiringPiSetupGpio() == -1){
		fprintf(stderr, "wiringPiSetupGpio() erorr\n");
		exit(1);
	}

	pinMode(SDATA, OUTPUT);
	pinMode(STR_CLK, OUTPUT);
	pinMode(SHR_CLK, OUTPUT);
	pinMode(SHR_CLEAR, OUTPUT);
	allclear();
}

void allclear(void)
{
	digitalWrite(SHR_CLEAR, 0);
	digitalWrite(SHR_CLEAR, 1);
	digitalWrite(STR_CLK, 0);
	digitalWrite(STR_CLK, 1);
}

void set16(uint16_t value)
{
	int i;

	for(i =0; i<16; i++){
		int mask = 1 << i;
		if((value&mask) == 0){
			digitalWrite(SDATA, 0);
		}else{
			digitalWrite(SDATA, 1);
		}
		digitalWrite(SHR_CLK, 0);
		digitalWrite(SHR_CLK, 1);
	}	
	digitalWrite(STR_CLK, 0);
	digitalWrite(STR_CLK, 1);
}

int main(void)
{
	int i, j, k;
	uint8_t col[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	uint8_t row[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x7E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; 
	uint16_t tmp;
	uint16_t temp;
	uint16_t before;
	init();

	while(1){

		for(j = 0 ; j < 16; j++) {
			printf("j = %d\n", j);
			for (k = 0 ; k < 50000 ; k++) {
				for(i = 0 ; i < 8 ; i++) {
					

				}
			}
		}
	}
	return 0;
}
/*
int main(void)
{
	int i, j;
	uint8_t row[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
	uint8_t col[] = {0xFF, 0x99, 0x00, 0x00, 0x00, 0x81, 0xC3, 0xE7};
}
 */
