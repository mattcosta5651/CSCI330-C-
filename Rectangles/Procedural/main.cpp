#include "procedural.h"
#include <iostream>

int main()
{
	int x1 = 1, y1 = 1, w1 = 10, h1 = 5;
	int x2 = 2, y2 = 3, w2 = 4, h2 = 2;
	int x3 = 2, y3 = 2, w3 = 4, h3 = 5;

	printRectangle('*', x1, y1, w1, h1);
	printRectangle('-', x2, y2, w2, h2);
	printRectangle('+', x3, y3, w3, h3);

	std::cout << std::endl;
	std::cout << "r1 area: " << area(w1, h1) << std::endl;
	std::cout << "r2 area: " << area(w2, h2) << std::endl;
	std::cout << "r3 area: " << area(w3, h3) << std::endl;

	std::cout << "r1 perimeter: " << perimeter(w1, h1) << std::endl;
	std::cout << "r2 perimeter: " << perimeter(w2, h2) << std::endl;
	std::cout << "r3 perimeter: " << perimeter(w3, h3) << std::endl;

	std::cout << "Does r1 contain r2? " 
		<< contains(x1, y1, w1, h1,
					x2, y2, w2, h2) << std::endl;

	std::cout << "Does r1 contain r3? " 
		<< contains(x1, y1, w1, h1,
					x3, y3, w3, h3) << std::endl;

}

void printRectangle(char ch, int x, int y, int w, int h)
{
	std::cout << "\n---------------" << std::endl;

	for(int i(0); i < y; i++)
	{
		std::cout << std::endl;
	}


	for(int k(0); k < h; k++)
	{
		for(int j(0); j < x; j++)
		{
			std::cout << " " ;
		}

		for(int l(0); l < w; l++)
		{
			std::cout << ch;
		}

		std::cout << std::endl;
	}
	std::cout << "\n---------------" << std::endl;

}

int area(int w, int h)
{
	return w*h;
}

int perimeter(int w, int h)
{
	return ((w*2) + (h*2)) -4;
}

bool contains(int x1, int y1, int w1, int h1,
	 		  int x2, int y2, int w2, int h2)
{
	if(x2 > x1 && y2 > y1 && w2< w1 && h2 < h1)
		return true;

	else
		return false;

}