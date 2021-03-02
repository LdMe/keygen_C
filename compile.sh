#!/bin/bash
#delete and create directory for binary files and executables

mkdir -p bin
if [ $# -ge 1 ];
then
	gcc ./source/*.c -o ./bin/$1
else
	gcc ./source/*.c -o ./bin/keygen
fi
#compile the source files