#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>
#include "StringList.h"

class InputParser
{
public:
	InputParser();
	~InputParser();
	void parseInputString(std::string string, StringList &output);
};

#endif //INPUTPARSER_H
