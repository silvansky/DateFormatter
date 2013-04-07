#include "DateFormatter.h"

#include "DatePartFormatterFactory.h"
#include "DatePartFormatter.h"
#include "StringList.h"

#include <iostream>

std::string DateFormatter::stringFromDate(time_t date, const std::string &format, const std::string &separator) throw(Exception &)
{
	DatePartFormatterFactory factory;

	StringList formatList(format, ' ');

	StringList resultingFormats;

	StringList::const_iterator it = formatList.begin();

	while (it != formatList.end())
	{
		DatePartFormatterPtr formatter = factory.createDatePartFormatter(*it);
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

std::string DateFormatter::stringFromCurrentDate(const std::string &format, const std::string &separator) throw(Exception &)
{
	time_t currentTime;
	time(&currentTime);
	return stringFromDate(currentTime, format, separator);
}
