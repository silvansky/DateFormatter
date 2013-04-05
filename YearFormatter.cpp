#include "YearFormatter.h"

#include <sstream>
#include <iomanip>

YearFormatter::YearFormatter()
{

}

YearFormatter::~YearFormatter()
{

}

std::string YearFormatter::formatNumber(const std::string &formatString, int number) throw(Exception &)
{
	std::stringstream stream;

	bool longYearFormat = (formatString.compare("YYYY") == 0);

	if ((formatString.compare("YY") != 0) && !longYearFormat)
	{
		stream << "DayFormatter::formatNumber: wrong format: " << formatString;
		throw (Exception(stream.str()));
	}

	stream << std::right;
	stream << std::setw(longYearFormat ? 4 : 2);
	stream << std::setfill('0');
	stream << number;
	return stream.str();
}

std::string YearFormatter::formatDate(const std::string &formatString, time_t date) throw(Exception &)
{
	struct tm *dateStruct = localtime(&date);
	return formatNumber(formatString, dateStruct->tm_year + 1900);
}

std::string YearFormatter::name()
{
	return "Year Formatter";
}
