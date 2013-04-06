#include <cxxtest/TestSuite.h>

#include "YearFormatter.h"

// test time: 1365266199

class YearFormatterTest : public CxxTest::TestSuite 
{
private:
	YearFormatter yf;
public:
	void testName()
	{
		TS_TRACE("Starting YearFormatter::name test");
		TS_ASSERT_EQUALS(yf.name(), "Year Formatter");
		TS_TRACE("Finishing YearFormatter::name test");
	}

	void testFormatNumber()
	{
		TS_TRACE("Starting YearFormatter::formatNumber test");

		TS_ASSERT_THROWS(yf.formatNumber("", 10), Exception &);
		TS_ASSERT_THROWS(yf.formatNumber("Y", 10), Exception &);
		TS_ASSERT_THROWS(yf.formatNumber("YYY", 10), Exception &);
		TS_ASSERT_THROWS(yf.formatNumber("YYYYY", 10), Exception &);
		TS_ASSERT_THROWS(yf.formatNumber("Z", 10), Exception &);

		TS_ASSERT_THROWS_NOTHING(yf.formatNumber("YY", 2013));
		TS_ASSERT_THROWS_NOTHING(yf.formatNumber("YYYY", 2013));
		TS_ASSERT_THROWS_NOTHING(yf.formatNumber("YY", -1783));
		TS_ASSERT_THROWS_NOTHING(yf.formatNumber("YYYY", -1783));

		TS_ASSERT_EQUALS(yf.formatNumber("YY", 2013), "13");
		TS_ASSERT_EQUALS(yf.formatNumber("YYYY", 2013), "2013");
		TS_ASSERT_EQUALS(yf.formatNumber("YY", -1783), "-83");
		TS_ASSERT_EQUALS(yf.formatNumber("YYYY", -1783), "-1783");

		TS_TRACE("Finishing YearFormatter::formatNumber test");
	}

	void testFormatDate()
	{
		TS_TRACE("Starting YearFormatter::formatDate test");

		time_t date = 1365266199; // 6 apr 2013

		TS_ASSERT_THROWS(yf.formatDate("", date), Exception &);
		TS_ASSERT_THROWS(yf.formatDate("Y", date), Exception &);
		TS_ASSERT_THROWS(yf.formatDate("YYY", date), Exception &);
		TS_ASSERT_THROWS(yf.formatDate("YYYYY", date), Exception &);
		TS_ASSERT_THROWS(yf.formatDate("Z", date), Exception &);

		TS_ASSERT_THROWS_NOTHING(yf.formatDate("YY", date));
		TS_ASSERT_THROWS_NOTHING(yf.formatDate("YYYY", date));

		TS_ASSERT_EQUALS(yf.formatDate("YY", date), "13");
		TS_ASSERT_EQUALS(yf.formatDate("YYYY", date), "2013");

		TS_TRACE("Finishing YearFormatter::formatDate test");
	}
};
