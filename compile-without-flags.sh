#!/usr/bin/bash

echo "Compiling Config class...."

g++ -mtune=native -std=c++11 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -c ./src/logger.cpp -I ./src

g++ -mtune=native -std=c++11 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -c ./src/config.cpp  -I ./src

echo "Done compiling Config class,compiling main now...."

g++ -mtune=native -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -c ./main.cpp -I ./src

g++ -o Kikyosama -lstdc++ main.o config.o logger.o 

echo "Done compiling !!!"
