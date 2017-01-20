#include <bcm2835.h>
#include <stdio.h>

#define PIN RPI_BPLUS_GPIO_J8_40

int main(int argc, char **argv){
	int i, num, loop;
	if(argc != 3)
		return 1;
	num = atoi(argv[1]);
	loop = atoi(argv[2]);

	if(!bcm2835_init())
		return 1;

	bcm2835_gpio_fsel(num, BCM2835_GPIO_FSEL_OUTP);

	if(loop == -1){
		while(1){
			bcm2835_gpio_write(num, HIGH);
			bcm2835_delay(500);
			bcm2835_gpio_write(num, LOW);
			bcm2835_delay(500);
		}
	}
	else{
		for(i=0; i<loop; i++){
			bcm2835_gpio_write(num, HIGH);
			bcm2835_delay(500);
			bcm2835_gpio_write(num, LOW);
			bcm2835_delay(500);
		}
	}
	bcm2835_close();
	return 0;
}
