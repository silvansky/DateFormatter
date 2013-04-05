#include <cxxtest/TestSuite.h>

#include "InputParser.h"

class InputParserTest : public CxxTest::TestSuite 
{
public:
	void testParseInputString()
	{
		InputParser parser;
		StringList list;
		parser.parseInputString("one two three", list);
		TS_ASSERT_EQUALS(list.size(), 3);
		TS_ASSERT_EQUALS(list.front().compare("one"), 0);
		TS_ASSERT_EQUALS(list.back().compare("three"), 0);
		list.pop_back();
		TS_ASSERT_EQUALS(list.back().compare("two"), 0);

		parser.parseInputString("single", list);
		TS_ASSERT_EQUALS(list.size(), 1);
		TS_ASSERT_EQUALS(list.front().compare("single"), 0);
	}
};
