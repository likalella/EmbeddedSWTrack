import RPi.GPIO as GPIO
import time
import os
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.IN)

try:
	while True:
		if GPIO.input(23)==0:
			os.system("shutdown -h now")
except KeyboardInterrupt:
	GPIO.cleanup()
