#ifndef FORMATTERFACTORY_H
#define FORMATTERFACTORY_H

#include <string>

class Formatter;

class FormatterFactory
{
public:
	FormatterFactory();
	~FormatterFactory();

	Formatter *createFormatter(std::string format);
};

#endif //FORMATTERFACTORY_H