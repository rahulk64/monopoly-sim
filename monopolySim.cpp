#include<iostream>
#include<string>
#include<ctime>
#include<cstdio>

using namespace std;

int playerMoney = 2500;
int compMoney = 2500;
int playerBoardP = 0;
int compBoardP = 0;
int playerJailTurns = 0;
int compJailTurns = 0;


class Place
{
public:
	string name;
	void setUp(string x, int placex, Place y);
	
}; 
Place places[40];

void Place::setUp(string x, int placex, Place y)
{
	y.name = x;
	places[placex] = y;
}

int main()
{
	//setup
	places[0].setUp("Start", 0, places[0]);
	places[1].setUp("Mediterranean Avenue", 1, places[1]);
	places[2].setUp("Community Chest", 2, places[2]);
	places[3].setUp("Baltic Avenue", 3, places[3]);
	places[4].setUp("Income Tax", 4, places[4]);
	places[5].setUp("Reading Railroad", 5, places[5]);
	places[6].setUp("Oriental Avenue", 6, places[6]);
	places[7].setUp("Chance", 7, places[7]);
	places[8].setUp("Vermont Avenue", 8, places[8]);
	places[9].setUp("Connecticut Avenue", 9, places[9]);
	places[10].setUp("Just Visiting", 10, places[10]);
	//Finish other 30 places
	
	cout << "Welcome!\n";
	
	return 0;
}
