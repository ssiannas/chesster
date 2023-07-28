#!/bin/bash
./build.sh || exit 1

cd build || exit 1
ctest --output-on-failure
