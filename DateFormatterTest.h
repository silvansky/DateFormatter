#include <cxxtest/TestSuite.h>

#include "DateFormatter.h"
#include "DayFormatter.h"
#include "MonthFormatter.h"
#include "YearFormatter.h"

/*
std::string stringFromDate(time_t date, const std::string &format, const std::string &separator) throw(Exception &);
std::string stringFromCurrentDate(const std::string &format, const std::string &separator) throw(Exception &);
*/

class DatePrinterTest : public CxxTest::TestSuite  
{
private:
	DateFormatter df;
public:
	void testStringFromDate()
	{
		TS_TRACE("Starting DatePrinter::stringFromDate test");

		time_t date = 1365266199; // 6 apr 2013

		TS_ASSERT_THROWS(df.stringFromDate(date, "KK", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, "---", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, "DD  MM", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, "YYYYY DD MMM", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, "        ", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, " ", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, "qwerty uiop", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, "MM DD YYYY Z", "-"), Exception &);
		TS_ASSERT_THROWS(df.stringFromDate(date, "DD MMMM", "-"), Exception &);

		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "", ""));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "", "-"));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "DD", ""));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "DD", "-"));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "MM", ""));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "MM", "-"));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "MMM", ""));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "MMM", "-"));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "YY", ""));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "YY", "-"));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "YYYY", ""));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "YYYY", "-"));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "DD MM YY", "\n"));
		TS_ASSERT_THROWS_NOTHING(df.stringFromDate(date, "YYYY DD MMM", "\t"));

		TS_ASSERT_EQUALS(df.stringFromDate(date, "DD MM YY", "-"), "06-04-13");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "DD MM YY", ""), "060413");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "DD MMM YY", "-"), "06-Apr-13");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "DD MMM YYYY", "-"), "06-Apr-2013");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "DD MM YY MMM YYYY DD", "|"), "06|04|13|Apr|2013|06");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "DD DD DD DD", ""), "06060606");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "YYYY DD MMM", "+"), "2013+06+Apr");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "DD", "-"), "06");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "MM", "-"), "04");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "MMM", "-"), "Apr");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "YY", "-"), "13");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "YYYY", "-"), "2013");
		TS_ASSERT_EQUALS(df.stringFromDate(date, "", "-"), "");

		TS_TRACE("Finishing DatePrinter::stringFromDate test");
	}
};