#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <algorithm>

using namespace std;

void readPixels(vector <vector<int> >& a, vector <vector<int> >& b, vector <vector<int> >& c)
{
	int count(0);
	vector<int> temp;
	
	vector<FileReader*> in;
	for(int i(0); i < 9; i++)
		in.push_back(new FileReader("PeskyImages/Pesky"+to_string(i+1)+".ppm"));	

	for(vector<FileReader*>::iterator itPrime = in.begin();
		itPrime!=in.end(); itPrime++)
	{
		try
		{		
			while (!(*itPrime)->endOfFile())
			{
				string line = (*itPrime)->readLine();

				if (isdigit(line[0]))
				{
					int x = atoi(line.c_str());
					
					if(x <= 255)
						temp.push_back(x);
					
				}
			}

			temp.erase(temp.begin());
		
			for (vector<int>::iterator it=temp.begin(); it!=temp.end(); it++)	
			{
				if((it-temp.begin())%3==0)	
					a[count].push_back(*it);

				else if((it-temp.begin())%3==1)
					b[count].push_back(*it);
				
				else if((it-temp.begin())%3==2)
					c[count].push_back(*it);
			}			

			temp.clear();
		}


		catch(string err)
		{
			cout << "Error: " << err << endl;
		}

		count++;
	}	
}

void filterPixels(vector< vector<int> >& a, vector < vector<int> >& b, vector< vector<int> >& c,
					vector<int>& x, vector<int>& y, vector<int>& z)
{
	vector<int> temp;
	int count(0);

	for(vector<int>::iterator it = a.at(0).begin(); it!=a.at(0).end(); it++)
	{
		for(int i(0); i < 9; i++)
			temp.push_back(a.at(i).at(count));

		sort(temp.begin(), temp.end());

		x.push_back(temp.at(temp.size()/2));
		count++;
		temp.clear();
	}

	count = 0;

	for(vector<int>::iterator it = b.at(0).begin(); it!=b.at(0).end(); it++)
	{
		for(int i(0); i < 9; i++)
			temp.push_back(b.at(i).at(count));

		sort(temp.begin(), temp.end());

		y.push_back(temp.at(temp.size()/2));
		count++;
		temp.clear();
	}

	count = 0;

	for(vector<int>::iterator it = c.at(0).begin(); it!=c.at(0).end(); it++)
	{
		for(int i(0); i < 9; i++)
			temp.push_back(c.at(i).at(count));

		sort(temp.begin(), temp.end());

		z.push_back(temp.at(temp.size()/2));
		count++;
		temp.clear();
	}

	count = 0;

}

void writePixels(vector<int>& a, vector<int>& b, vector<int>& c)
{
	ofstream outputFile;
	outputFile.open("PeskyFixed.ppm");

	outputFile << "P3" << endl;
	outputFile << "# CREATOR: main.cpp" << endl;
	outputFile << "495 557" << endl;
	outputFile << "255" << endl;

	int count(0);

	for(int i(0); i < (a.size())*3; i++)
	{
		outputFile << a.at(count) << endl;
		outputFile << b.at(count) << endl;
		outputFile << c.at(count) << endl;

		count++;
	}

	outputFile.close();
}

int main(int argc, char * argv[])
{
	vector< vector<int> > r(9);
	vector< vector<int> > g(9);
	vector< vector<int> > b(9);

	vector<int> rFinal;
	vector<int> gFinal;
	vector<int> bFinal;

	readPixels(r, g, b);
	filterPixels(r, g, b, rFinal, gFinal, bFinal);
	writePixels(rFinal, gFinal, bFinal);
}