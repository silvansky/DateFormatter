#ifndef DATEPRINTER_H
#define DATEPRINTER_H

#include <string>
#include "Exception.h"

class DatePrinter
{
public:
	std::string stringFromDate(time_t date, const std::string &format, const std::string &separator) throw(Exception &);
	std::string stringFromCurrentDate(const std::string &format, const std::string &separator) throw(Exception &);
};

#endif //DATEPRINTER_H
