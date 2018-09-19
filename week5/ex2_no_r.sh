#!/bin/bash 
if test ! -f numbers
then
    echo 0 > numbers
fi
if ln numbers numbers.lock
	then                                                                    
	for i in `seq 1 200`;
	do
		n=`tail -1 numbers`
		n=$((n+1))
		echo $n >> numbers
	done
	rm numbers.lock
fi