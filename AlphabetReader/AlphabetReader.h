#ifndef ALPHABETREADER_H
#define ALPHABETREADER_H

#include <iostream>

class AlphabetReader
{
public:
	AlphabetReader();
	void readFile();
	void countNumbers();
	int getNumbers(std::string c) const

private:
	std::vector<std::string> strings;
	std::vector<int> counts;
};


#endif