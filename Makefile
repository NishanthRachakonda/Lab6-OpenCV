# compiler options
CC=gcc
CXX=g++
CFLAGS=-c -o
CPPFLAGS=-std=c++11 -c -o
CVFLAGS=$(shell pkg-config --cflags --libs opencv4)
LDFLAGS=-I/usr/local/Cellar/opencv/4.5.0_3/include/opencv4

# file paths
SRC=src
BIN=bin
UTILS=utils
IO=$(BIN)/image $(BIN)/image_io $(BIN)/wrapper

all: build

build: dirs
	@echo "Building boiler code."
	$(CXX) $(CPPFLAGS) $(BIN)/image $(UTILS)/image.c
	$(CXX) $(LDFLAGS) $(CPPFLAGS) $(BIN)/wrapper $(UTILS)/wrapper.cpp
	$(CXX) $(LDFLAGS) $(CPPFLAGS) $(BIN)/image_io $(UTILS)/image_io.cpp

run:
	@echo "Linking code with boiler code."
	$(CXX) $(CPPFLAGS) $(BIN)/$(output)_temp $(SRC)/$(file)
	$(CXX) $(CVFLAGS) -o $(BIN)/$(output) $(IO) $(BIN)/$(output)_temp

dirs:; mkdir -p $(BIN)
clean:; rm -rf $(BIN)