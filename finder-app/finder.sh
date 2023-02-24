#!/bin/sh
if [ $# != 2 ]
then
	echo "Invalid number of arguments: $#"
	exit 1
else
	if  [ ! -d $1 ]
	then
		echo "Directory not found: $1"
		exit 1
	fi
fi
num_of_files=$(find $1 -type f | wc -l)
num_of_matches=$(grep -r $2 $1* | wc -l)
echo "The number of files are $num_of_files and the number of matching lines are $num_of_matches"
