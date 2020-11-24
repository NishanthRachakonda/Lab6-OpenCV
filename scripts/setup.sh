#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: bash scripts/setup.sh <linux/macos>."
    exit 1
fi

if [[ $1 == "linux" ]]
then
    sudo apt update && sudo apt install -y cmake g++ wget unzip
    sudo apt-get install pkg-config
    wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
    unzip opencv.zip
    mkdir -p build && cd build
    cmake  ../opencv-master
    cmake --build .
elif [[ $1 == "macos" ]]
then
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    brew install opencv
    brew install pkg-config
fi

pkg-config --cflags --libs opencv4