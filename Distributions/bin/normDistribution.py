#!/usr/bin/python


import math
import time
import random
import sys

ms = time.time()*1000.0
random.seed(ms)
for i in range(int(sys.argv[1])):
	print math.sqrt(2*-math.log(1-random.random()))*math.cos(2*math.pi*random.random())
