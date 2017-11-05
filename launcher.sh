#!/bin/bash

echo "starting application..."
#sleep 2

#------ argument selection -------#
if [ $# -eq 0 ] || [ $1 == '-h' ] || [ $1 == '-help' ];
then
    echo "usage -> -v [version] -h [tree_height]"
    exit 0
fi

while getopts v:h: option
do
  case "${option}"
    in
    v) VERSION=${OPTARG};;
    h) HEIGHT=${OPTARG};;
  esac
done

echo "Number of arguments -> $#"
echo $VERSION
echo $HEIGHT

#if [ "$1" == "test" ]; then
#  echo "hellow"
#fi

#------ compilation of code ------#


#----------- execution -----------#


#----------- greetings -----------#
