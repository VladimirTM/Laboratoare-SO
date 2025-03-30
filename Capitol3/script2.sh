#!bin/bash

if [ $# -ne 4 ]
then
    echo "Numar de argumente invalid"
    exit 1
fi

if [ $1 != "-i" ]
then
    echo "Argumentul 1 este invalid"
    exit 1
fi

if ! [ -f $2 ]
then
    echo "Argumentul 2 nu este fisier"
    exit 1
fi

if [ $3 != "-o" ]
then
    echo "Argumentul 3 este invalid"
    exit 1
fi

> $4

for line in `cat $2`
do
    echo $line | grep -qE '^(http|https)://[a-z][a-zA-Z0-9\-\.]*\.(com|ro|eu);([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2}$' && echo "OK" >> $4 || echo "ERROR" >> $4
done
