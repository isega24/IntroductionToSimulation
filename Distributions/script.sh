#!/bin/bash

rm ./results/$1

echo To use this script you should give:
echo    1 the distribution generator on ./bin directory as first argument
echo    2 Number of sample to take from the distribution as second argument
echo    3 How many parts you want to divide the sample as third argument
echo ""
./bin/$1 $2 >> ./results/$1
echo Sample taked
./paint.py ./results/$1 $3
