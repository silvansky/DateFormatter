#include "DatePrinter.h"

#include "FormatterFactory.h"
#include "InputParser.h"
#include "Formatter.h"

#include <iostream>

std::string DatePrinter::stringFromDate(time_t date, const std::string &format, const std::string &separator) throw(Exception &)
{
	InputParser parser;
	FormatterFactory factory;

	StringList formatList;
	parser.parseInputString(format, formatList);

	StringList resultingFormats;

	StringList::const_iterator it = formatList.begin();
	while (it != formatList.end())
	{
		FormatterPtr formatter = factory.createFormatter(*it);
		if (!formatter)
		{
			throw(Exception("Unknown format: " + *it));
			return "";
		}
		try
		{
			resultingFormats.push_back(formatter.get()->formatDate(*it, date));
		}
		catch (Exception &e)
		{
			throw(Exception(std::string("Formatter exception: ") + e.what()));
			return "";
		}
		it++;
	}

	return resultingFormats.join(separator);
}

std::string DatePrinter::stringFromCurrentDate(const std::string &format, const std::string &separator) throw(Exception &)
{
	time_t currentTime;
	time(&currentTime);
	return stringFromDate(currentTime, format, separator);
}
