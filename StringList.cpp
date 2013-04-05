#include "StringList.h"

std::string StringList::join(const std::string &separator)
{
	std::string result;
	StringList::const_iterator it = begin();
	while (it != end())
	{
		result += *it;
		result += separator;
	}
}
