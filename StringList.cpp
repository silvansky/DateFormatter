#include "StringList.h"

#include <iostream>

std::string StringList::join(const std::string &separator)
{
	std::string result;
	StringList::const_iterator it = begin();
	while (it != end())
	{
		result += *it;
		it++;
		if (it != end())
		{
			result += separator;
		}
	}
	return result;
}

void StringList::printContents()
{
	StringList::const_iterator it = begin();
	while (it != end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}
