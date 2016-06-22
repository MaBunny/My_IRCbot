#!/usr/bin/bash

echo "Compiling Config class...."

g++ -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -c ./Src/config.cpp

echo "Done compiling Config class,compiling main now...."

g++ -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -o Kikyosama ./main.cpp ./config.o -I ./Src

echo "Done compiling !!!"
