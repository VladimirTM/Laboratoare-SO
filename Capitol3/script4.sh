#!bin/bash

if [ $# -ne 2 ]
then
    echo "Argumente invalide"
    exit 1
fi

if ! [ -d $1 ]
then
    echo "Argumentul 1 nu este un director"
    exit 1
fi

if ! [ -d $2 ]
then
    echo "Argumentul 2 nu este un director"
    exit 1
fi

cd $1

for item in *
do
    if [ -d $item ]
    then
	cd $item
	gcc -Wall -o program *.c
	if [ $? -ne 0 ]
	then
	    echo "Nu a reusit compilarea"
	fi
	pwd
	for testFile in `ls ../../$2`
	do
	    ./program < ../../$2/$testFile
	done
	rm program
	cd ..
    fi
done

cd ..
