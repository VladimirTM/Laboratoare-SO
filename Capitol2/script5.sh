#!bin/sh
if [ $# -ne 2 ]
then 
	echo "Argumente invalide"
	exit 1
fi
directory=$1
file=$2
if ! [ -d "$directory" ]
then
	echo "Nu am primit un director"
	exit 3
fi
cd $directory
files=`ls | grep ".txt"`
for file in $files
do
	numarCaractere=`wc -m $file`
	echo "TOTAL $numarCaractere"
done > $file
