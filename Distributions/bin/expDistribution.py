#!/usr/bin/python


import math
import time
import random
import sys

ms = time.time()*1000.0
random.seed(ms)
for i in range(int(sys.argv[1])):
	print -math.log(1-random.random())
