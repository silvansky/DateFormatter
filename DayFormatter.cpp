#include "DayFormatter.h"

#include <sstream>
#include <iomanip>
#include <ctime>

DayFormatter::DayFormatter()
{
}

DayFormatter::~DayFormatter()
{
}

std::string DayFormatter::formatNumber(const std::string &formatString, int number) throw(Exception &)
{
	std::stringstream stream;

	if (formatString != "DD")
	{
		stream << "DayFormatter::formatNumber: wrong format: " << formatString;
		throw (Exception(stream.str()));
	}

	if ((number < 1) || (number > 31))
	{
		stream << "DayFormatter::formatNumber: number out of range: " << number << " (expecgted 1..31)";
		throw (Exception(stream.str()));
	}

	stream << std::right;
	stream << std::setw(2);
	stream << std::setfill('0');
	stream << number;
	return stream.str();
}

std::string DayFormatter::formatDate(const std::string &formatString, time_t date) throw(Exception &)
{
	struct tm *dateStruct = localtime(&date);
	return formatNumber(formatString, dateStruct->tm_mday);
}

std::string DayFormatter::name()
{
	return "Day Formatter";
}
