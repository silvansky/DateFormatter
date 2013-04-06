#include "MonthFormatter.h"

#include <sstream>
#include <iomanip>

MonthFormatter::MonthFormatter()
{
	monthNames.push_back("Jan");
	monthNames.push_back("Feb");
	monthNames.push_back("Mar");
	monthNames.push_back("Apr");
	monthNames.push_back("May");
	monthNames.push_back("Jun");
	monthNames.push_back("Jul");
	monthNames.push_back("Aug");
	monthNames.push_back("Sep");
	monthNames.push_back("Oct");
	monthNames.push_back("Nov");
	monthNames.push_back("Dec");
}

MonthFormatter::~MonthFormatter()
{
}

std::string MonthFormatter::formatNumber(const std::string &formatString, int number) throw(Exception &)
{
	std::stringstream stream;

	bool longMonthFormat = (formatString == "MMM");

	if ((formatString != "MM") && !longMonthFormat)
	{
		stream << "DayFormatter::formatNumber: wrong format: " << formatString;
		throw (Exception(stream.str()));
	}

	if ((number < 1) || (number > 12))
	{
		stream << "DayFormatter::formatNumber: number out of range: " << number << " (expecgted 1..12)";
		throw (Exception(stream.str()));
	}

	if (longMonthFormat)
	{
		stream << monthNames[number - 1];
	}
	else
	{
		stream << std::right;
		stream << std::setw(2);
		stream << std::setfill('0');
		stream << number;
	}

	return stream.str();
}

std::string MonthFormatter::formatDate(const std::string &formatString, time_t date) throw(Exception &)
{
	struct tm *dateStruct = localtime(&date);
	return formatNumber(formatString, dateStruct->tm_mon + 1);
}

std::string MonthFormatter::name()
{
	return "Month Formatter";
}
