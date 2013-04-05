#include <iostream>
#include <string>

#include "InputParser.h"

void printUsage()
{
	std::cout 
			<< "Usage: " << std::endl
			<< "    dateformatter \"format_string\" \"separator\" " << std::endl
			<< "Format string patterns:" << std::endl
			<< "    DD - day number" << std::endl
			<< "    MM - month number" << std::endl
			<< "    MMM - month short name" << std::endl
			<< "    YY - short year number" << std::endl
			<< "    YYYY - long year number" << std::endl
			<< "All patterns must be separated by single space." << std::endl
			<< std::endl
			<< "Example:" << std::endl
			<< "    dateformatter \"DD MMM YY\" \"-\" " << std::endl
			<< "Output:" << std::endl
			<< "    05-Apr-13" << std::endl
			<< std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printUsage();
		return 1;
	}

	std::string input = std::string(argv[1]);
	std::string separator = std::string(argv[2]);

#ifdef DEBUG
	std::cout << "Input string: " << input << std::endl;
	std::cout << "Separator: " << separator << std::endl;
#endif

	return 0;
}