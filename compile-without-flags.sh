#!/usr/bin/bash

echo "Compiling Config class...."

g++ -std=c++11 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -L. -lstdc++ -c ./src/logger.cpp -I ./src

g++ -std=c++11 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -L. -lstdc++ -c ./src/config.cpp  -I ./src

echo "Done compiling Config class,compiling main now...."

g++ -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic  -L. -lstdc++ -c ./main.cpp -I ./src

g++ -o Kikyosama -lstdc++ main.o config.o logger.o 

echo "Done compiling !!!"
