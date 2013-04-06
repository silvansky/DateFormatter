#include <cxxtest/TestSuite.h>

#include "InputParser.h"

class InputParserTest : public CxxTest::TestSuite 
{
public:
	void testParseInputString()
	{
		TS_TRACE("Starting InputParser::parseInputString test");
		InputParser parser;
		StringList list;
		parser.parseInputString("one two three", list);
		TS_ASSERT_EQUALS(list.size(), 3);
		TS_ASSERT_EQUALS(list.front(), "one");
		TS_ASSERT_EQUALS(list.back(), "three");
		list.pop_back();
		TS_ASSERT_EQUALS(list.back(), "two");

		parser.parseInputString("single", list);
		TS_ASSERT_EQUALS(list.size(), 1);
		TS_ASSERT_EQUALS(list.front(), "single");
		TS_TRACE("Finishing InputParser::parseInputString test");
	}
};
