#!/bin/bash
./build.sh $1

cd build || exit
ctest --output-on-failure
