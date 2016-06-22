#!/usr/bin/bash

echo "Compiling Config class and main.cpp......."

gcc -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -c -g3 ./Src/config.cpp -I ./Src

g++ -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -g3 ./main.cpp ./config.o -I ./Src

echo "Done compiling !!!"
