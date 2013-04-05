#!/bin/sh

rm -f runner.cpp

make

rm -f main.o

OBJECTS=$(ls *.o)

HEADERS_FILE=cxxtest-headers

rm -f ${HEADERS_FILE}

ls -1 *Test.h > ${HEADERS_FILE}

./cxxtest/bin/cxxtestgen --have-std --runner=ErrorPrinter --headers=${HEADERS_FILE} -o runner.cpp

clang -I./cxxtest -std=c++11 -lstdc++ -o testrunner runner.cpp $OBJECTS

./testrunner -v

rm -f runner.cpp
