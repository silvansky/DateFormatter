#include <cxxtest/TestSuite.h>

#include "DatePartFormatterFactory.h"
#include "DatePartFormatter.h"

class DatePartFormatterFactoryTest : public CxxTest::TestSuite  
{
public:
	void testCreateDatePartFormatter()
	{
		TS_TRACE("Starting DatePartFormatterFactory::createDatePartFormatter test");

		DatePartFormatterPtr formatter;
		DatePartFormatterFactory factory;

		TS_ASSERT_THROWS_NOTHING(factory.createDatePartFormatter(""));
		TS_ASSERT_THROWS_NOTHING(factory.createDatePartFormatter("DD"));
		TS_ASSERT_THROWS_NOTHING(factory.createDatePartFormatter("MM"));
		TS_ASSERT_THROWS_NOTHING(factory.createDatePartFormatter("MMM"));
		TS_ASSERT_THROWS_NOTHING(factory.createDatePartFormatter("YY"));
		TS_ASSERT_THROWS_NOTHING(factory.createDatePartFormatter("YYYY"));
		TS_ASSERT_THROWS_NOTHING(factory.createDatePartFormatter("ZZ"));

		formatter = factory.createDatePartFormatter("DD");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Day Formatter");

		formatter = factory.createDatePartFormatter("Day");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Day Formatter");

		formatter = factory.createDatePartFormatter("MM");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Month Formatter");

		formatter = factory.createDatePartFormatter("Month");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Month Formatter");

		formatter = factory.createDatePartFormatter("MMM");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Month Formatter");

		formatter = factory.createDatePartFormatter("YY");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Year Formatter");

		formatter = factory.createDatePartFormatter("YYYY");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Year Formatter");

		formatter = factory.createDatePartFormatter("Year");
		TS_ASSERT_EQUALS(formatter.get()->name(), "Year Formatter");

		formatter = factory.createDatePartFormatter("");
		TS_ASSERT_EQUALS(formatter.get(), (DatePartFormatter *)NULL);

		formatter = factory.createDatePartFormatter("ZZ");
		TS_ASSERT_EQUALS(formatter.get(), (DatePartFormatter *)NULL);

		TS_TRACE("Finishing DatePartFormatterFactory::createDatePartFormatter test");
	}
};