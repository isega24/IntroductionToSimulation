#!/bin/bash

rm ./results/$1
./bin/$1 $2 >> ./results/$1
echo Sample taked
./paint.py ./results/$1 $3
