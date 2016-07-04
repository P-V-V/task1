#!/bin/sh
set -x
cd build
cmake ..
make run_all_tests
cd ..
./bin/run_all_tests
