#!/bin/bash
./build.sh

cd build || exit
ctest --verbose --output-on-failure
