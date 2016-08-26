#!/usr/bin/env bash

if [ ! -e build ]; then
  mkdir build
fi

g++ -std=c++14 -O3 -o build/jam.out template.cpp

