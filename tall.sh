#!/bin/bash

make clean
clear
make 

for f in ./testing/test*
do
	echo Testing $f 
	time ./project0 < $f
done

#echo Testing unichars
#time ./project0 < ./testing/unichars.txt
