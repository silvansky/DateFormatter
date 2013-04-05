#ifndef STRINGLIST_H
#define STRINGLIST_H

#include <list>
#include <string>

class StringList : std::list<std::string>
{
public:
	std::string join(const std::string &separator);
};

#endif //STRINGLIST_H