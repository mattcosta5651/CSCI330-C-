#include "AlphabetReader.h"
#include <iostream>

int main(int argc, char * argv[])
{
	AlphabetReader reader();
	reader.readFile();
	reader.countNumbers();

	char x;
	while(!x.equals("q"))	
	{
		std::cout << "Enter a capital letter A-Z or lowercase q to quit: ";
		std::cin >> x;
		reader.getNumbers(x);
		std::cout << "" << std::endl;
	}


}