#!/bin/bash
set echo off

make clean
make all
clear

cat test1 | ./project0
