#!/bin/sh
if [ $# != 2 ]
then
	echo "Invalid number of arguments: $#"
	exit 1
fi
install -D /dev/null $1
if [ $? != 0 ]
then
	echo "Create file or directory operation has failed"
	exit 1
fi
echo $2 > $1
