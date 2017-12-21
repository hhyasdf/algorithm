#!/bin/bash

# to generate the directory of problem
# use command line "./generate,.sh problemname" to generate

if [ $# == 0 ]; then
    echo "error: you should have specified the problem name!"

else 
    for i in $@; do
        cp -r ./code_template/example ./problems/$i
    done
fi
