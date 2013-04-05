#include <iostream>
#include <string>

#include "InputParser.h"
#include "FormatterFactory.h"
#include "Formatter.h"

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

	InputParser parser;
	StringList formatList;
	parser.parseInputString(input, formatList);

	FormatterFactory factory;

	StringList resultingFormats;
	time_t currentTime;
	time(&currentTime);

	StringList::const_iterator it = formatList.begin();
	while (it != formatList.end())
	{
		FormatterPtr formatter = factory.createFormatter(*it);
		try
		{
			std::cout << "Formatting \"" << *it << "\" with formatter: " << formatter.get()->name() << std::endl;
			resultingFormats.push_back(formatter.get()->formatDate(*it, currentTime));
		}
		catch (Exception &e)
		{
			std::cout << "Formatter exception: " << e.what() << std::endl;
		}
		it++;
	}

	std::string resultingString = resultingFormats.join(separator);
	std::cout << resultingString << std::endl;

	return 0;
}
