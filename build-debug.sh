#!/bin/bash
mkdir build-debug;
cd ./build-debug ;
cmake -DCMAKE_BUILD_TYPE=Debug \
	-DALTURA=600 \
	-DLARGURA=800 \
  .. ;
cmake --build . --verbose ;
