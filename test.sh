#!/bin/bash

./build.sh $1 || exit 1

cd build || exit 1
ctest --output-on-failure
