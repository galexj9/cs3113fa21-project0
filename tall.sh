#!/bin/bash

clear
make clean
make 

for f in ./testing/test*
do
	echo Testing $f 
	./project0 < $f
done
