#ifndef STRINGLIST_H
#define STRINGLIST_H

#include <list>
#include <string>

class StringList : public std::list<std::string>
{
public:
	std::string join(const std::string &separator);
	void printContents();
};

#endif //STRINGLIST_H
