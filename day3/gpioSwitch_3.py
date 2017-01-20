import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(27, GPIO.OUT)
GPIO.setup(22, GPIO.OUT)
GPIO.setup(26, GPIO.IN)
num=0
try:
	while True:
		GPIO.output(17, False)
		GPIO.output(27, False)
		GPIO.output(22, False)
		if GPIO.input(26)==0:
			num = num+1
		if num%4 == 0:
			time.sleep(1)
		elif num%4 == 1:
			GPIO.output(17, True)
			time.sleep(1)
		elif num%4 == 2:
			GPIO.output(27, True)
			time.sleep(1)
		elif num%4 == 3:
			GPIO.output(22, True)
			time.sleep(1)

except KeyboardInterrupt:
	GPIO.cleanup()
