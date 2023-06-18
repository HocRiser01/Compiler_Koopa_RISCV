#!/bin/bash

BASEDIR=$(dirname $0)
cd $BASEDIR/..
g++ $(find . -name '*.cpp') -g -L./Lib -lkoopa -o compiler
