import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(27, GPIO.OUT)
GPIO.setup(22, GPIO.OUT)
GPIO.setup(13, GPIO.IN)
GPIO.setup(19, GPIO.IN)
GPIO.setup(26, GPIO.IN)
num=0
try:
	while True:
		GPIO.output(17, False)
		GPIO.output(27, False)
		GPIO.output(22, False)
		if GPIO.input(13)==0:
			num = num+1
		if GPIO.input(19)==0:
			num = num+1
		if GPIO.input(26)==0:
			num = num+1
		if num == 0:
			time.sleep(1)
		elif num == 1:
			GPIO.output(17, True)
			time.sleep(1)
		elif num == 2:
			GPIO.output(17, True)
			GPIO.output(27, True)
			time.sleep(1)
		elif num == 3:
			GPIO.output(17, True)
			GPIO.output(27, True)
			GPIO.output(22, True)
			time.sleep(1)
		num=0

except KeyboardInterrupt:
	GPIO.cleanup()
