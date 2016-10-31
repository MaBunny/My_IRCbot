#!/usr/bin/bash

echo "Compiling Config class and main.cpp......."

g++ -std=c++11 -fmessage-length=100 -fdiagnostics-color=always -Wall -Wextra -pedantic -L. -lstdc++ -c -g3 ./src/logger.cpp -I ./src

g++ -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -L. -lstdc++ -c -g3 ./src/config.cpp -I ./src

g++ -std=c++11 -fmessage-length=10 -fdiagnostics-color=always -Wall -Wextra -pedantic -L. -lstdc++ -g3 ./main.cpp -I ./src

g++ -lstdc++ main.o config.o logger.o

rm ./config.o

echo "Done compiling !!!"
