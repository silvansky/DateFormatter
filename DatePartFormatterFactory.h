#ifndef DATEPARTFORMATTERFACTORY_H
#define DATEPARTFORMATTERFACTORY_H

#include <string>
#include <tr1/memory>

class DatePartFormatter;
typedef std::tr1::shared_ptr<DatePartFormatter> DatePartFormatterPtr;

class DatePartFormatterFactory
{
public:
	DatePartFormatterFactory();
	~DatePartFormatterFactory();

	DatePartFormatterPtr createDatePartFormatter(const std::string &format);
};

#endif //DATEPARTFORMATTERFACTORY_H
