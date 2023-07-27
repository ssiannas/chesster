#!/bin/bash
./build.sh

cd build || exit
ctest --output-on-failure
