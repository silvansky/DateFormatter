#ifndef DAYFORMATTER_H
#define DAYFORMATTER_H

#include "Formatter.h"

class DayFormatter : public Formatter
{
public:
	DayFormatter();
	virtual ~DayFormatter();

	virtual std::string formatNumber(const std::string &formatString, int number) throw(Exception &);
	virtual std::string formatDate(const std::string &formatString, time_t date) throw(Exception &);
	virtual std::string name();
};

#endif //DAYFORMATTER_H