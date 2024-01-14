#!/bin/bash

cd "$(dirname "$0")"/../build

cmake ..

make

if [ $? -eq 0 ]; then
    echo "Build successful."
    ./MBTATracker
else
    echo "Build failed."
fi