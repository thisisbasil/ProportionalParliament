#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <algorithm>
#include "parseat.h"
#include "circprop.h"
#include "StrategyFactory.h"
using namespace std;

int getNumSeats(ifstream& file)
{
	string line;
	while(getline(file,line))
	{
		int temp = atoi(line.c_str());
		if (temp > 0)
			return temp;
	}

	return -1;	
}

bool skipline(string line)
{
	if (line[0] == '#' || line[0] == '\0' || isspace(line[0]))	
		return true;
	return false;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "format: parseat <input file>" << endl;
		return 0;	
	}
	
	ifstream file;
	file.open(argv[1]);
	if (file.is_open())
	{
		int numseats = getNumSeats(file);
		parseat model(numseats);
		
		string line;
		while(getline(file,line))
		{
			string name;
			long numvotes;
			if(skipline(line))
				continue;
			istringstream iss(line);
			iss >> name;
			iss >> numvotes;
			model.add(name,numvotes);	
		}
		
		StrategyFacory factory;
		model.setStrategy(factory.getStrategy("circprop"));
		model.runModel();
		model.printResults();
	}
	else
	{
		cout << argv[1] << " is not present." << endl;
		return 1;	
	}
	return 1;
}
