#include "InputParser.h"

#include <iostream>

InputParser::InputParser()
{

}

InputParser::~InputParser()
{

}

void InputParser::parseInputString(std::string string, StringList &output)
{
	output.clear();
	size_t lastWhiespacePos = 0;
	size_t spaceIndex = 0;
	while (spaceIndex != std::string::npos)
	{
		spaceIndex = string.find_first_of(' ', lastWhiespacePos + 1);
		std::string part = string.substr(lastWhiespacePos, spaceIndex - lastWhiespacePos);
		output.push_back(part);
		lastWhiespacePos = spaceIndex + 1;
	}
}
