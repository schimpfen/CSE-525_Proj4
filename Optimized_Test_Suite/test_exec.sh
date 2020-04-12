#!/bin/sh

for x in a b c d e f g
do
	printf "\n\nIN $x.o\n"
	./$x.o 20 1 0
	./$x.o 200 1 0
	./$x.o 2000 1 0
	./$x.o 20 1 1
	./$x.o 200 1 1
	./$x.o 2000 1 1
done
		
