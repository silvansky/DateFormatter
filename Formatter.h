#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>

class Formatter
{
public:
	virtual std::string formatNumber(std::string formatString, int number) = 0;
};

#endif //FORMATTER_H
