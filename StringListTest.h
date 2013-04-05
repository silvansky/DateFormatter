#include <cxxtest/TestSuite.h>

#include "StringList.h"

class StringListTestSuite : public CxxTest::TestSuite
{
public:
	void testJoin()
	{
		TS_TRACE("Starting StringList::join test");
		StringList list;
		std::string joint;

		joint = list.join("--");

		TS_ASSERT_EQUALS(joint.compare(""), 0);

		list.push_back("1");

		joint = list.join("-");

		TS_ASSERT_EQUALS(joint.compare("1"), 0);

		list.push_back("2");
		list.push_back("3");
		list.push_back("4");

		joint = list.join("-");

		TS_ASSERT_EQUALS(joint.compare("1-2-3-4"), 0);
		TS_TRACE("Finishing StringList::join test");
	}
};
