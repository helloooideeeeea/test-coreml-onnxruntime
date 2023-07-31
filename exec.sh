#!/bin/bash
# create build directory
mkdir -p build && cd build

# run cmake
cmake ..

# run make
make

# execute the binary
./onnxruntime_test