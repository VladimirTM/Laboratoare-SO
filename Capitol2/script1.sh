#!/bin/bash
if test $# -ne 3
then echo "Argumente invalide"
else
n1=$1
n2=$2
n3=$3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then echo $n1
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then echo $n2
else echo $n3
fi
fi
