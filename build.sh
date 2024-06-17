#! /usr/bin/bash

g++ src/main/main.cpp -lSDL2 -lSDL2_image -Lsrc/assets/... -o pixel src/*.cpp include/*.hpp