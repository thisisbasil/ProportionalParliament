#include "circprop.h"

vector<party> CircProp::run()
{
		cout << "Circular Proportional Model..." << endl;
		getTotalVotes();
		getPercentages();
		removeIrrelevantAndSort();
		getSeats();
		return parties;
}

void CircProp::getTotalVotes()
{
		vector<party>::iterator it;
		for(auto i : parties)
			totalvotes += i.numvotes;
		cout << "Total votes cast: " << totalvotes << endl;
}

void CircProp::getPercentages()
{
		vector<party>::iterator it;
		for(it = parties.begin(); it != parties.end(); it++)
			it->percent = (double)it->numvotes/(double)totalvotes;	
}

void CircProp::removeIrrelevantAndSort()
{
		vector<party> temp;
		vector<party>::iterator it;
		for(it = parties.begin(); it != parties.end(); it++)
		{
			if (it->percent > threashold)
				temp.push_back(*it);
		}

		// sort using lambda and in descending order
		sort(temp.begin(), temp.end(),
			[] (party const& a, party const& b)
			{
				return a.numvotes > b.numvotes;
			});
		parties.clear();
		parties = temp;
}

void CircProp::getSeats()
{
		vector<party>::iterator it;
		int total = 0;
		for(it = parties.begin(); it != parties.end(); it++)
		{
				it->numseats = floor(it->percent*numseats);
				if((it->numseats+total) > numseats)
				{
						it->numseats = numseats-total;
						total = numseats;
						break;
				}
				total += it->numseats;
		}
		
		it = parties.begin();
		while(total < numseats)
		{
			it->numseats++;
			total++;
			it++;
			if (it == parties.end())
				it = parties.begin();
		}
}
