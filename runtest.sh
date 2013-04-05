#!/bin/sh

GEN="./cxxtest/bin/cxxtestgen --error-printer -o runner.cpp"

function runTest
{
	echo "Testing $1"
	$GEN $1
	clang -I./cxxtest -std=c++11 -lstdc++ -o testrunner runner.cpp $2
	./testrunner
}

echo "Running tests..."

runTest StringListTest.h "StringList.cpp"

runTest ExceptionTest.h "Exception.cpp"