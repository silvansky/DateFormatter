#ifndef YEARFORMATTER_H
#define YEARFORMATTER_H

#include "Formatter.h"

class YearFormatter : public Formatter
{
public:
	YearFormatter();
	~YearFormatter();

	virtual std::string formatNumber(std::string formatString, int number);
};

#endif //YEARFORMATTER_H
