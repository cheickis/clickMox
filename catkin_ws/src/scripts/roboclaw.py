#!/usr/local/bin/python3.6
#from roboclaw import Roboclaw
import time
#from roboclaw import Roboclaw
from roboclaw_3 import Roboclaw
#rc = Roboclaw("/dev/ttyACM0",115200)
rc = Roboclaw("/dev/serial0", 115200)
rc.Open()

while 1:
	#Get version string
	version = rc.ReadVersion(0x80)
	if version[0]==False:
		print ("GETVERSION Failed")
	else:
		print (repr(version[1]))
	time.sleep(1)
