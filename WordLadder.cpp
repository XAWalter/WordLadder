#include "WordLadder.h"

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <iterator>
#include <exception>
#include <stack>
#include <queue>

WordLadder::WordLadder() {
	std::string a;
	std::ifstream dictFile;

	try {

		dictFile.open("dictionary.txt");
		if (dictFile.good()) {

			while (dictFile >> a) {
				dict.push_back(a);
			}

			dictFile.close();
		}
		else {
			throw 1;
		}

		//geeksforgeeks helped with iterator
		for (std::list<std::string>::iterator ptr = dict.begin(); ptr != dict.end(); ptr++) {
			if ((*ptr).length() != 5) {
				throw 2;
			}
		}
	}
	catch (int x) {
		if (x == 1) {
			std::cout << "File did not open correctly." << std::endl;
		}
		if (x == 2) {
			std::cout << "File contains words of invalid length" << std::endl;
		}
	}
}

void WordLadder::outputLadder(const std::string &first, const std::string &second) {
	bool skip = false;
	bool found = false;
	std::stack<std::string> s;
	std::queue<std::stack<std::string>> q;
	int count = 0;

	//std::queue<std::string> copy;

	std::string comp;


	dict.remove(first);
	//dict.remove(second);
	
	//first word in stack
	s.push(first);

	//push first stack onto queue
	q.push(s);

	while (!q.empty()) {
		//count++;
		//std::cout << count << std::endl;
		comp = q.front().top();
		std::list<std::string>::iterator ptr = dict.begin();
		while (ptr != dict.end()) {

			if (compare(comp, *ptr)) {

				//copy of front stack + new Word
				std::stack<std::string> nS;
//				while(!q.front().empty()) {
//					copy.push(q.front().top());
//					q.front().pop();
//				}
//				while (!copy.empty()) {
//					q.front().push(copy.front());
//					nS.push(copy.front());
//					copy.pop();
//				}
				this->copyStack(q.front(), nS, *ptr);

				nS.push(*ptr);
				//if at final word
				if (*ptr == second) {
					while(!nS.empty()) {
						std::cout << nS.top() << std::endl;
						nS.pop();
					}
					found = true;
					return;
				}
				else {
					skip = true;
					q.push(nS);
					std::string newWord;
					newWord = *ptr;
					ptr++;
					dict.remove(newWord);
				}
			}
			if (!skip) {
				ptr++;
			}
			skip = false;
		}
		q.pop();
	}
	if (!found) {
		std::cout << "Word ladder not found" << std::endl;
	}



}

void WordLadder::copyStack(std::stack<std::string> &a, std::stack<std::string> &b, std::string newWord) {
	std::list<std::string> copy;

	while (!a.empty()) {
		copy.push_back(a.top());
		a.pop();
	}
//	a.push(newWord);
//	b.push(newWord);
	while (!copy.empty()) {
		a.push(copy.back());
		b.push(copy.back());
		copy.pop_back();
	}
}

//stackoverflow
bool WordLadder::compare(std::string a, std::string b) {
	int difChar = 0;

	for (int i = 0; i < 5; i++) {
		if (a.at(i) != b.at(i)) {
			difChar++;
			if (difChar > 1) {
				return false;
			}

		}
	}
	return true;
}