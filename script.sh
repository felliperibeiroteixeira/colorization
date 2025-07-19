#!/bin/bash
clear
./configure --clean
./configure
cmake .
make -j $(nproc)
