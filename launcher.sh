#!/bin/bash

echo "starting application..."
#sleep 2

#------ argument selection -------#
if [ $# -eq 0 ] || [ $1 == '-h' ] || [ $1 == '-help' ];
then
    echo "usage -> -e [example #] -h [tree_height]"
    exit 0
fi

while getopts e:h: option
do
  case "${option}"
    in
    e) EXAMPLE=${OPTARG};;
    h) HEIGHT=${OPTARG};;
  esac
done

echo "Number of arguments -> $#"
echo $EXAMPLE
echo $HEIGHT

#if [ "$1" == "test" ]; then
#  echo "hellow"
#fi

#------ compilation of code ------#


#----------- execution -----------#


#----------- greetings -----------#
