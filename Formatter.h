#ifndef FORMATTER_H
#define FORMATTER_H

#include "Exception.h"
#include <string>

class Formatter
{
public:
	virtual ~Formatter() {};
	virtual std::string formatNumber(const std::string &formatString, int number) throw(Exception &) = 0;
	virtual std::string formatDate(const std::string &formatString, time_t date) throw(Exception &) = 0;
	virtual std::string name() = 0;
};

#endif //FORMATTER_H
