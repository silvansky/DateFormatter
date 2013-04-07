#include "FormatterFactory.h"

#include "DayFormatter.h"
#include "MonthFormatter.h"
#include "YearFormatter.h"

FormatterFactory::FormatterFactory()
{
}

FormatterFactory::~FormatterFactory()
{
}

DatePartFormatterPtr FormatterFactory::createFormatter(const std::string &format)
{
	char firstCharacter = format[0];
	DatePartFormatterPtr ptr;
	switch (firstCharacter)
	{
		case 'D':
			ptr.reset(new DayFormatter());
			break;
		case 'M':
			ptr.reset(new MonthFormatter());
			break;
		case 'Y':
			ptr.reset(new YearFormatter());
			break;
	}
	return ptr;
}
