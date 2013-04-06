#include <cxxtest/TestSuite.h>

#include "DayFormatter.h"

// test time: 1365266199

class DayFormatterTest : public CxxTest::TestSuite 
{
private:
	DayFormatter df;
public:
	void testName()
	{
		TS_TRACE("Starting DayFormatter::name test");
		TS_ASSERT_EQUALS(df.name(), "Day Formatter");
		TS_TRACE("Finishing DayFormatter::name test");
	}

	void testFormatNumber()
	{
		TS_TRACE("Starting DayFormatter::formatNumber test");

		TS_ASSERT_THROWS(df.formatNumber("", 10), Exception &);
		TS_ASSERT_THROWS(df.formatNumber("D", 10), Exception &);
		TS_ASSERT_THROWS(df.formatNumber("DDD", 10), Exception &);
		TS_ASSERT_THROWS(df.formatNumber("Z", 10), Exception &);
		TS_ASSERT_THROWS(df.formatNumber("DD", 0), Exception &);
		TS_ASSERT_THROWS(df.formatNumber("DD", -5), Exception &);
		TS_ASSERT_THROWS(df.formatNumber("DD", 50), Exception &);
		TS_ASSERT_THROWS(df.formatNumber("DD", 32), Exception &);

		TS_ASSERT_THROWS_NOTHING(df.formatNumber("DD", 2));

		TS_ASSERT_EQUALS(df.formatNumber("DD", 2), "02");
		TS_ASSERT_EQUALS(df.formatNumber("DD", 12), "12");

		TS_TRACE("Finishing DayFormatter::formatNumber test");
	}

	void testFormatDate()
	{
		TS_TRACE("Starting DayFormatter::formatDate test");

		time_t date = 1365266199; // 6 apr 2013

		TS_ASSERT_THROWS(df.formatDate("", date), Exception &);
		TS_ASSERT_THROWS(df.formatDate("D", date), Exception &);
		TS_ASSERT_THROWS(df.formatDate("DDD", date), Exception &);
		TS_ASSERT_THROWS(df.formatDate("Z", date), Exception &);

		TS_ASSERT_THROWS_NOTHING(df.formatDate("DD", date));

		TS_ASSERT_EQUALS(df.formatDate("DD", date), "06");

		TS_TRACE("Finishing DayFormatter::formatDate test");
	}
};
