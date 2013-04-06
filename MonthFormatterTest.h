#include <cxxtest/TestSuite.h>

#include "MonthFormatter.h"

// test time: 1365266199

class MonthFormatterTest : public CxxTest::TestSuite 
{
private:
	MonthFormatter mf;
public:
	void testName()
	{
		TS_TRACE("Starting MonthFormatter::name test");
		TS_ASSERT_EQUALS(mf.name(), "Month Formatter");
		TS_TRACE("Finishing MonthFormatter::name test");
	}

	void testFormatNumber()
	{
		TS_TRACE("Starting MonthFormatter::formatNumber test");

		TS_ASSERT_THROWS(mf.formatNumber("", 10), Exception &);
		TS_ASSERT_THROWS(mf.formatNumber("M", 10), Exception &);
		TS_ASSERT_THROWS(mf.formatNumber("MMMM", 10), Exception &);
		TS_ASSERT_THROWS(mf.formatNumber("Z", 10), Exception &);
		TS_ASSERT_THROWS(mf.formatNumber("MM", 0), Exception &);
		TS_ASSERT_THROWS(mf.formatNumber("MM", -5), Exception &);
		TS_ASSERT_THROWS(mf.formatNumber("MM", 50), Exception &);
		TS_ASSERT_THROWS(mf.formatNumber("MM", 13), Exception &);

		TS_ASSERT_THROWS_NOTHING(mf.formatNumber("MM", 5));
		TS_ASSERT_THROWS_NOTHING(mf.formatNumber("MMM", 6));

		TS_ASSERT_EQUALS(mf.formatNumber("MM", 5), "05");
		TS_ASSERT_EQUALS(mf.formatNumber("MM", 12), "12");

		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 1), "Jan");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 2), "Feb");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 3), "Mar");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 4), "Apr");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 5), "May");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 6), "Jun");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 7), "Jul");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 8), "Aug");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 9), "Sep");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 10), "Oct");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 11), "Nov");
		TS_ASSERT_EQUALS(mf.formatNumber("MMM", 12), "Dec");

		TS_TRACE("Finishing MonthFormatter::formatNumber test");
	}

	void testFormatDate()
	{
		TS_TRACE("Starting MonthFormatter::formatDate test");

		time_t date = 1365266199; // 6 apr 2013

		TS_ASSERT_THROWS(mf.formatDate("", date), Exception &);
		TS_ASSERT_THROWS(mf.formatDate("M", date), Exception &);
		TS_ASSERT_THROWS(mf.formatDate("MMMM", date), Exception &);
		TS_ASSERT_THROWS(mf.formatDate("Z", date), Exception &);

		TS_ASSERT_THROWS_NOTHING(mf.formatDate("MM", date));
		TS_ASSERT_THROWS_NOTHING(mf.formatDate("MMM", date));

		TS_ASSERT_EQUALS(mf.formatDate("MM", date), "04");
		TS_ASSERT_EQUALS(mf.formatDate("MMM", date), "Apr");

		TS_TRACE("Finishing MonthFormatter::formatDate test");
	}
};
