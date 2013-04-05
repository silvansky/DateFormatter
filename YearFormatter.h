#ifndef YEARFORMATTER_H
#define YEARFORMATTER_H

#include "Formatter.h"

class YearFormatter : public Formatter
{
public:
	YearFormatter();
	virtual ~YearFormatter();

	virtual std::string formatNumber(const std::string &formatString, int number) throw(Exception &);
	virtual std::string formatDate(const std::string &formatString, time_t date) throw(Exception &);
	virtual std::string name();
};

#endif //YEARFORMATTER_H
