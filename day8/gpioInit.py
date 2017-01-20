import RPi.GPIO as GPIO
import sys

class GpioSetting(object):
	SDATA = 6
	STR_CLK = 13
	SHR_CLK = 19
	SHR_CLEAR = 26

	def __init__(self):
		try:
			GPIO.setmode(GPIO.BCM)
		except:
			print("Fail to GPIO init")
			sys.exit()
		GPIO.setup(self.SDATA, GPIO.OUT)
		GPIO.setup(self.STR_CLK, GPIO.OUT)
		GPIO.setup(self.SHR_CLK, GPIO.OUT)
		GPIO.setup(self.SHR_CLEAR, GPIO.OUT)
		self.allclear()
	
	def allclear(self):
		GPIO.output(self.SHR_CLEAR, False)
		GPIO.output(self.SHR_CLEAR, True)
		GPIO.output(self.STR_CLK, False)
		GPIO.output(self.STR_CLK, True)

	def set16(self, value):
		for i in range(16):
			mask = 1 << i
			if (value&mask) == 0:
				GPIO.output(self.SDATA, False)
			else:
				GPIO.output(self.SDATA, True)
			GPIO.output(self.SHR_CLK, False)
			GPIO.output(self.SHR_CLK, True)
		GPIO.output(self.STR_CLK, False)
		GPIO.output(self.STR_CLK, True)

