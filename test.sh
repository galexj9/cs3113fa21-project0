#!/bin/bash
set echo off
clear
make clean
make all

cat test1 | ./project0
