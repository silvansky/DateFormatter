#ifndef MONTHFORMATTER_H
#define MONTHFORMATTER_H

#include "DatePartFormatter.h"
#include <vector>

class MonthFormatter : public DatePartFormatter
{
public:
	MonthFormatter();
	virtual ~MonthFormatter();

	virtual std::string formatNumber(const std::string &formatString, int number) throw(Exception &);
	virtual std::string formatDate(const std::string &formatString, time_t date) throw(Exception &);
	virtual std::string name();
private:
	std::vector<std::string> monthNames;
};

#endif //MONTHFORMATTER_H
