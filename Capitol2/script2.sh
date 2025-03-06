#!/bin/bash
if [ $# -ne 3 ]
then echo "Argumente invalide"
else
	n1=$1
	op=$2
	n2=$3
	case "$op" in
	"+") expr $n1 + $n2;;
	"-") expr $n1 - $n2;;
	"*") expr $n1 \* $n2;;
	"/") expr $n1 / $n2;;
	"%") expr $n1 % $n2;;
	*) echo "Operator invalid"
	esac
fi
