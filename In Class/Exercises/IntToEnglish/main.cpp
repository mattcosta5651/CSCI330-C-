#include <iostream>

using namespace std;

void checkForError()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		throw std::string("bad input");
	}

}

int main()
{
	try
	{
		int 
		cout << "PLEASE ENTER AN INTEGER: " << endl;
	}

	catch(string err)
	{
		cout << err << endl;
	}
}