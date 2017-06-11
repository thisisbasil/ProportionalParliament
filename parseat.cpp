#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <algorithm>
using namespace std;

const double THREASHOLD = 0.0009;

struct party
{
	string name;
	unsigned long numvotes;
	unsigned int numseats;
	double percent;
	party() { numvotes = numseats = percent = 0; }
	bool operator>(const party& other) { return numvotes > other.numvotes; }
	bool operator<(const party& other) { return numvotes < other.numvotes; }
	bool operator==(const party& other) { return numvotes == other.numvotes; }
	bool operator!=(const party& other) { return numvotes != other.numvotes; }
	friend ostream& operator<<(ostream& s, const party& other)
	{
		s << "Name: " << other.name 
		  << "\tVotes: " << other.numvotes
		  << "\tPercent: " << other.percent
		  << "\tSeats: " << other.numseats;
		return s;
	}
};

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

vector<party> getVoteTallies(ifstream& file, int numseats)
{
	vector<party> retval;
	string line;
	unsigned long total=0;
	while(getline(file,line))
	{
		party temp;
		if(skipline(line))
			continue;
		istringstream iss(line);
		iss >> temp.name;
		iss >> temp.numvotes;
		total += temp.numvotes;
		retval.push_back(temp);
	}
	for(vector<party>::iterator it=retval.begin(); 
	    it!=retval.end(); it++)
		it->percent = (double)it->numvotes/(double)total;
			
	cout << "Number of parties: " << retval.size() << endl;
	return retval;
}

vector<party> getSeats(ifstream& file, vector<party> parties, int numseats)
{
	vector<party> retval;
	vector<party>::iterator it;
	//get quick total
	unsigned long tot=0;
	for(auto i : parties)
		tot+=i.numvotes;
	cout << "Votes cast: " << tot << endl;
	
	//remove irrelevant parties
	for(it = parties.begin(); it != parties.end(); it++)
	{
		if (it->percent > THREASHOLD)
			retval.push_back(*it);
	}
	sort(retval.begin(), retval.end(),
			[](party const& a, party const& b) 
			{ 
				return a.numvotes > b.numvotes; 
			});
	int total = 0;
	for(it=retval.begin(); it!=retval.end(); it++)
	{
		it->numseats = floor(it->percent*numseats);
		if (it->numseats + total > numseats)
		{
			it->numseats = numseats - total;
			total = numseats;
			break;
		}
		total += it->numseats;	
	}	
	it = retval.begin();
	while(total < numseats)
	{
		it->numseats++;
		total++;
		it++;
		if (it == retval.end())
			it=retval.begin();	
	}
	return retval;
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
		cout << "Number of seats: " << numseats << endl;
		vector<party> parties = getVoteTallies(file,numseats);	
		parties = getSeats(file,parties, numseats);
		for(auto i : parties)
			cout << i << endl;	
	}
	else
	{
		cout << argv[1] << " is not present." << endl;
		return 1;	
	}
	return 1;
}
