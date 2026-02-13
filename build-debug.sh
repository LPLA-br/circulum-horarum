#!/bin/bash
cd ./build-debug ;
cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  .. ;
cmake --build . --verbose ;
