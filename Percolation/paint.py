#!/usr/bin/python
import matplotlib.pyplot as pyplt
import sys

infile = open(sys.argv[1],'r')
X = []
Y = []
for lin in infile:
    line = lin.split()
    X.append(float(line[0]))
    Y.append(float(line[1]))

pyplt.plot(X,Y)
pyplt.show()
infile.close()
