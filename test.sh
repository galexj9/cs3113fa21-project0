#!/bin/bash
exe=decode

make clean
make all

cat test1 | ./project0
