#!/usr/bin/python
import matplotlib.pyplot as pyplt
import sys
infile = open(sys.argv[1], 'r')
sample = []
for lin in infile:
    	sample.append(float(lin))
sample.sort()
min = sample[0]
max = sample[len(sample)-1]
dist = max-min
parts = int(sys.argv[2])
lenParts = dist*1.0/parts
j = 0
jBEF = 0
X = []
Y = []
for i in range(parts):
	sum = 0.0
	while sample[j] < i*lenParts:
		sum =  sum + sample[j]
		j = j+1

	if j > jBEF :
		X.append((sample[jBEF]+sample[j])/2.0)
		Y.append(j - jBEF)
	jBEF = j


pyplt.plot(X,Y)
pyplt.show()
infile.close()
