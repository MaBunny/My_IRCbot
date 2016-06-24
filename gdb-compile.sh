#!/usr/bin/bash

echo "Compiling Config class and main.cpp......."

gcc -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -L. -lstdc++ -c -g3 ./Src/config.cpp -I ./Src

g++ -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -L. -lstdc++ -g3 ./main.cpp ./config.o -I ./Src

rm ./config.o

echo "Done compiling !!!"
