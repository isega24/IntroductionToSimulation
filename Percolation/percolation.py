#!/usr/bin/python -O

import sys
import random
import time

def wayFound1(percMap):
    for i in range(len(percMap)):
        if wayFound(percMap,0,i):
            return True

    return False
def wayFound(percMap,i,j):
    if i < 0 or j < 0 or i >= len(percMap) or j >= len(percMap):
        return False
    elif percMap[i][j] == 0 :
        return False
    else:
        percMap[i][j] = 0
        if i + 1 == len(percMap):
            return True
        elif wayFound(percMap,i,j+1) or wayFound(percMap,i+1,j) or wayFound(percMap,i-1,j) or wayFound(percMap,i,j-1):
            return True
        else:
            return False

def creatPercMap(N,prob):
    percMap = []
    ms = time.time()*1000.0
    random.seed(ms)

    # Percolation map creation
    percMap = []
    for i in range(N):
        percMap.append([])
        for j in range(N):
            if random.random() > prob:
                percMap[i].append(0)
            else:
                percMap[i].append(1)
    if wayFound1(percMap):
        return 1
    else:
        return 0

sum = 0.0
times = int(sys.argv[1])
N = int(sys.argv[2])
prob = float(sys.argv[3])/100.0
for i in range(times):
    s = creatPercMap(N,prob)
    sum = sum + s

print str(prob) + " " + str(sum*1.0/times)
