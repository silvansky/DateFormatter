#include <cxxtest/TestSuite.h>

#include "Exception.h"

class ExceptionTest : public CxxTest::TestSuite 
{
public:
	void testWhat()
	{
		Exception e("test");
		TS_ASSERT_EQUALS(std::string(e.what()).compare("test"), 0);
	}
};
