#!bin/sh
if [ $# -ne 2 ]
then 
	echo "Argumente invalide"
	exit 1
fi
directory=$1
mode=$2
if [ "$mode" != "r" ] && [ "$mode" != "w" ] && [ "$mode" != "x" ]
then
	echo "Drept invalid"
	exit 2
fi
if ! [ -d "$directory" ]
then
	echo "Nu am primit un director"
	exit 3
fi
cd $directory
files=`ls | grep ".txt"`
for file in $files
do
	chmod +$mode $file
done
