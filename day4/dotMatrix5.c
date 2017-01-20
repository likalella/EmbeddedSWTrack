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
	uint8_t col[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x00, 0x00, 0x46, 0x58, 0x60, 0x60, 0x58, 0x46, 0x00, 0x00, 0x7E, 0x40, 0x7E, 0x40, 0x40, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	uint8_t row[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x7E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x72, 0x18, 0x24, 0x24, 0x42, 0x42, 0x00, 0x00, 0x7E, 0x52, 0x52, 0x52, 0x52, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; 
	uint16_t tmp;
	uint16_t temp;
	uint16_t before;
	init();

	while(1){
		for(j=0; j<32; j++){
			printf("j = %d\n", j);
			for(k=0; k<50000; k++){
				for(i = 0;i < 8; i++){
					
					temp=0;
					if(i+j < 8){
						before = 0x00;
					}else {
						before = 0xff-col[(j+i)-8];
					}

					switch(j%8){
						case 0:
							temp = (0xff-col[j+i]);
							break;
						case 1:
							before = before << 1;
							temp = before | ((0xff-col[j+i])>> 7);
							break;
						case 2:
							before = before << 2;
							temp = before | ((0xff-col[j+i])>> 6);
							break;
						case 3:
							before = before << 3;
							temp = before | ((0xff-col[j+i])>> 5);
							break;
						case 4:
							before = before << 3;
							temp = before | ((0xff-col[j+i])>> 4);
							break;
						case 5:
							before = before << 5;
							temp = before | ((0xff-col[j+i])>> 3);
							break;
						case 6:
							before = before << 6;
							temp = before | ((0xff-col[j+i])>> 2);
							break;
						case 7:
							before = before << 7;
							temp = before | ((0xff-col[j+i])>> 1);
							break;
					}
					tmp = (row[j+i] << 8) | temp;
					set16(tmp);
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
