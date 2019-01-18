#include "WordLadder.h"

#include <iostream>
#include <list>
#include <string>
#include <fstream>

WordLadder::WordLadder() {
	std::string a;
	std::ifstream dictFile;
	dictFile.open("dictionary.txt");
	while (dictFile >> a) {
		dict.push_back(a);
	}

	dictFile.close();

	for (auto v : dict) {
		std::cout << v << std::endl;
	}
}