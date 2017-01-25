#include "FileReader.h"
#include "StringFunctions.h"
#include "AlphabetReader.h"

#include <iostream>
#include <vector>
#include <string>

AlphabetReader::AlphabetReader() : strings(), counts(26, 0)
{}

void readFile()
{	
	try
	{
		FileReader in("wordlist.txt");
		while (!in.endOfFile())
		{
			std::string line = in.readLine();
			if (line.size() > 0)
			{
				strings.push_back(line);
			}
		}
	
		for (std::vector<std::string>::iterator it=strings.begin(); 
				it!=strings.end(); it++)	
		{
			std::string line = *it;
			*it = StringFunctions::toupper(line);			
		}
	}
	catch (std::string err)
	{
		std::cout << "Error: " << err << std::endl;
	}
}

void countNumbers()
{
	for(std::vector<int>::iterator it=counts.begin(); it!=strings.end(); it++)
	{
		counts[it] = 0;
	}

	for(std::vector<std::string>::iterator it=strings.begin(); 
				it!=strings.end(); it++)
	{
		std::string c = *it.first();

		if(c.compare(0, 1, "A") == 0)
			counts[0]++;
		if(c.compare(0, 1, "B") == 0)
			counts[1]++;
		if(c.compare(0, 1, "C") == 0)
			counts[2]++;
		if(c.compare(0, 1, "D") == 0)
			counts[3]++;
		if(c.compare(0, 1, "E") == 0)
			counts[4]++;
		if(c.compare(0, 1, "F") == 0)
			counts[5]++;
		if(c.compare(0, 1, "G") == 0)
			counts[6]++;
		if(c.compare(0, 1, "H") == 0)
			counts[7]++;
		if(c.compare(0, 1, "I") == 0)
			counts[8]++;
		if(c.compare(0, 1, "J") == 0)
			counts[9]++;
		if(c.compare(0, 1, "K") == 0)
			counts[10]++;
		if(c.compare(0, 1, "L") == 0)
			counts[11]++;
		if(c.compare(0, 1, "M") == 0)
			counts[12]++;
		if(c.compare(0, 1, "N") == 0)
			counts[13]++;
		if(c.compare(0, 1, "O") == 0)
			counts[14]++;
		if(c.compare(0, 1, "P") == 0)
			counts[15]++;
		if(c.compare(0, 1, "Q") == 0)
			counts[16]++;
		if(c.compare(0, 1, "R") == 0)
			counts[17]++;
		if(c.compare(0, 1, "S") == 0)
			counts[18]++;
		if(c.compare(0, 1, "T") == 0)
			counts[19]++;
		if(c.compare(0, 1, "U") == 0)
			counts[20]++;
		if(c.compare(0, 1, "V") == 0)
			counts[21]++;
		if(c.compare(0, 1, "W") == 0)
			counts[22]++;
		if(c.compare(0, 1, "X") == 0)
			counts[23]++;
		if(c.compare(0, 1, "Y") == 0)
			counts[24]++;
		if(c.compare(0, 1, "Z") == 0)
			counts[25]++;	
	}
}

int getCount(std::string c) const
{
	int x(0);

	if(c.compare(0, 1, "A") == 0)
		x = counts[0];
	if(c.compare(0, 1, "B") == 0)
		x = counts[1];
	if(c.compare(0, 1, "C") == 0)
		x = counts[2];
	if(c.compare(0, 1, "D") == 0)
		x = counts[3];
	if(c.compare(0, 1, "E") == 0)
		x = counts[4];
	if(c.compare(0, 1, "F") == 0)
		x = counts[5];
	if(c.compare(0, 1, "G") == 0)
		x = counts[6];
	if(c.compare(0, 1, "H") == 0)
		x = counts[7];
	if(c.compare(0, 1, "I") == 0)
		x = counts[8];
	if(c.compare(0, 1, "J") == 0)
		x = counts[9];
	if(c.compare(0, 1, "K") == 0)
		x = counts[10];
	if(c.compare(0, 1, "L") == 0)
		x = counts[11];
	if(c.compare(0, 1, "M") == 0)
		x = counts[12];
	if(c.compare(0, 1, "N") == 0)
		x = counts[13];
	if(c.compare(0, 1, "O") == 0)
		x = counts[14];
	if(c.compare(0, 1, "P") == 0)
		x = counts[15];
	if(c.compare(0, 1, "Q") == 0)
		x = counts[16];
	if(c.compare(0, 1, "R") == 0)
		x = counts[17];
	if(c.compare(0, 1, "S") == 0)
		x = counts[18];
	if(c.compare(0, 1, "T") == 0)
		x = counts[19];
	if(c.compare(0, 1, "U") == 0)
		x = counts[20];
	if(c.compare(0, 1, "V") == 0)
		x = counts[21];
	if(c.compare(0, 1, "W") == 0)
		x = counts[22];
	if(c.compare(0, 1, "X") == 0)
		x = counts[23];
	if(c.compare(0, 1, "Y") == 0)
		x = counts[24];
	if(c.compare(0, 1, "Z") == 0)
		x = counts[25];

	return x;
}