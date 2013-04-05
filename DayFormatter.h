#ifndef DAYFORMATTER_H
#define DAYFORMATTER_H

#include "Formatter.h"

class DayFormatter : public Formatter
{
public:
	DayFormatter();
	~DayFormatter();

	virtual std::string formatNumber(std::string formatString, int number);
};

#endif //DAYFORMATTER_H
