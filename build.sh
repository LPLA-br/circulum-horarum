#!/bin/bash
mkdir build;
cd ./build ;
cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" \
	-DALTURA=600 \
	-DLARGURA=800 \
	..;
cmake --build . ;

