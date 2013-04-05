#ifndef FORMATTERFACTORY_H
#define FORMATTERFACTORY_H

#include <string>
#include <tr1/memory>

class Formatter;
typedef std::tr1::shared_ptr<Formatter> FormatterPtr;

class FormatterFactory
{
public:
	FormatterFactory();
	~FormatterFactory();

	FormatterPtr createFormatter(std::string format);
};

#endif //FORMATTERFACTORY_H
