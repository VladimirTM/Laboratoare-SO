#!bin/sh
mkdir Test
cd Test
name="test"
i=0
while test $i -lt 10
do
	touch "$name$i.txt"
	i=`expr $i + 1`
done
while test $i -gt 5
do
	touch "$name$i.c"
	i=`expr $i - 1`
done
