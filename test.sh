#!/bin/bash

LEVEL=$1
PROJECT_FOLDER=$(pwd)
DOCKER_NAME="maxxing/compiler-dev"

if [ -z "$LEVEL" ]; then
    echo "PLEASE SELECT A LEVEL."
    exit 1
fi
if [ $LEVEL -eq 0 ]; then
    docker run -it --rm -v $PROJECT_FOLDER:/root/compiler $DOCKER_NAME bash
elif [ $LEVEL -eq 1 ]; then
    docker run -it --rm -v $PROJECT_FOLDER:/root/compiler $DOCKER_NAME \
	    autotest -koopa -s lv1 /root/compiler
elif [ $LEVEL -eq 2 ]; then
    docker run -it --rm -v $PROJECT_FOLDER:/root/compiler $DOCKER_NAME \
        autotest -riscv -s lv1 /root/compiler
elif [ $LEVEL -eq 3 ]; then
    #
    docker run -it --rm -v $PROJECT_FOLDER:/root/compiler $DOCKER_NAME \
        autotest -koopa -s lv3 /root/compiler
    docker run -it --rm -v $PROJECT_FOLDER:/root/compiler $DOCKER_NAME \
        autotest -riscv -s lv3 /root/compiler
else
    echo -en "LEVEL = $LEVEL auto test not implemented in script."
fi
