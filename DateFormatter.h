#ifndef DATEFORMATTER_H
#define DATEFORMATTER_H

#include <string>
#include "Exception.h"

class DateFormatter
{
public:
	std::string stringFromDate(time_t date, const std::string &format, const std::string &separator) throw(Exception &);
	std::string stringFromCurrentDate(const std::string &format, const std::string &separator) throw(Exception &);
};

#endif //DATEFORMATTER_H
