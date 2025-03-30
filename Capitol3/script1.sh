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
    echo $line | grep -qE '^[a-zA-Z][a-zA-Z0-9\-]*@[a-zA-Z][a-zA-Z0-9]*\.(com|ro|eu);([1-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])(\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])){2}\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-4])$' && echo "OK" >> $4 || echo "ERROR" >> $4
done
