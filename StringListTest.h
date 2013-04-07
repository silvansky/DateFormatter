#include <cxxtest/TestSuite.h>

#include "StringList.h"

class StringListTestSuite : public CxxTest::TestSuite
{
public:
	void testStringList()
	{
		TS_TRACE("Starting StringList::StringList test");

		StringList list("one two three", ' ');
		TS_ASSERT_EQUALS(list.size(), 3);
		TS_ASSERT_EQUALS(list.front(), "one");
		TS_ASSERT_EQUALS(list.back(), "three");
		list.pop_back();
		TS_ASSERT_EQUALS(list.back(), "two");

		list = StringList("single", ' ');
		TS_ASSERT_EQUALS(list.size(), 1);
		TS_ASSERT_EQUALS(list.front(), "single");

		list = StringList("", ' ');
		TS_ASSERT_EQUALS(list.size(), 0);

		TS_TRACE("Finishing StringList::StringList test");
	}
	void testJoin()
	{
		TS_TRACE("Starting StringList::join test");
		StringList list;
		std::string joint;

		joint = list.join("--");

		TS_ASSERT_EQUALS(joint, "");

		list.push_back("1");

		joint = list.join("-");

		TS_ASSERT_EQUALS(joint, "1");

		list.push_back("2");
		list.push_back("3");
		list.push_back("4");

		joint = list.join("-");

		TS_ASSERT_EQUALS(joint, "1-2-3-4");

		TS_TRACE("Finishing StringList::join test");
	}
};
