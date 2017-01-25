#include "FileReader.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	try
	{
		string filename;
		cout << "Pleae enter the name of the file: " << endl;
		getline(cin, filename);
		FileReader file(filename);

		vector<char> bytes;
		int lines(-1);

		while(!file.endOfFile())
		{
			string line = file.readLine();

			for (std::string::const_iterator it=line.cbegin(); it!=line.cend(); it++)
				bytes.push_back(*it);

			lines=lines+1;

		}

		cout << "FILE SIZE: " << to_string(bytes.size()+lines) << endl;
	}

	catch(string e)
	{
		cout << e << endl;
	}

}