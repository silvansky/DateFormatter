#ifndef MONTHFORMATTER_H
#define MONTHFORMATTER_H

#include "Formatter.h"

class MonthFormatter : public Formatter
{
public:
	MonthFormatter();
	~MonthFormatter();

	virtual std::string formatNumber(std::string formatString, int number);
};

#endif //MONTHFORMATTER_H
