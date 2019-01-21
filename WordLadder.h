#ifndef WORDLADDER_H
#define WORDLADDER_H

#include <iostream>
#include <list>
#include <stack>

class WordLadder {
public:
	WordLadder();

	void outputLadder(const std::string&, const std::string&);

	bool compare(std::string, std::string);

	void copyStack(std::stack <std::string>&, std::stack<std::string>&, std::string);

private:
	std::list<std::string> dict;
};
#endif // !WORDLADDER_H
