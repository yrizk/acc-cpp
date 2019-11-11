#!/bin/bash
program=$1
gcc -g -o $1 $1.cpp -lstdc++ && ./$1
