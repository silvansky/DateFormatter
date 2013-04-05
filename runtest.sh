#!/bin/sh

rm -f runner.cpp

make

rm -f main.o

OBJECTS=$(ls *.o)

./cxxtest/bin/cxxtestgen --have-std --runner=ErrorPrinter --headers=cxxtest-headers -o runner.cpp

clang -I./cxxtest -std=c++11 -lstdc++ -o testrunner runner.cpp $OBJECTS

./testrunner -v

rm -f runner.cpp
