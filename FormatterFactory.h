#ifndef FORMATTERFACTORY_H
#define FORMATTERFACTORY_H

#include <string>
#include <tr1/memory>

class DatePartFormatter;
typedef std::tr1::shared_ptr<DatePartFormatter> DatePartFormatterPtr;

class FormatterFactory
{
public:
	FormatterFactory();
	~FormatterFactory();

	DatePartFormatterPtr createFormatter(const std::string &format);
};

#endif //FORMATTERFACTORY_H
