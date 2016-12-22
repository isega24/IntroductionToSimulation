#!/bin/bash

rm ./results/perc.txt
for(( i=0; i <= 100; i = i + 1 ))
do
	./percolation.py 100 60 $i >> ./results/perc.txt
done
echo Results collected.
./paint.py ./results/perc.txt
