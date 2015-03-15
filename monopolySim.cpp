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
	int priceBuy;
	int priceLand;
}; 
Place places[40];

void Place::setUp(string x, int placex, Place y)
{
	y.name = x;
	places[placex] = y;
	//
}

void setUp();

int main()
{
	setUp();
	srand(time(NULL));

	//gameStart
	cout << "Welcome!\n";
	

	
	
	return 0;
}

void setUp()
{
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
	places[11].setUp("St. Charles Place", 11, places[11]);
	places[12].setUp("Electric Company", 12, places[12]);
	places[13].setUp("States Avenue", 13, places[13]);
	places[14].setUp("Virginia Avenue", 14, places[14]);
	places[15].setUp("Pennsylvania Railroad", 15, places[15]);
	places[16].setUp("St. James Place", 16, places[16]);
	places[17] = places[2];
	places[18].setUp("Tennessee Avenue", 18, places[18]);
	places[19].setUp("New York Avenue", 19, places[19]);
	places[20].setUp("Free Parking", 20, places[20]);
	places[21].setUp("Kentucky Avenue", 21, places[21]);
	places[22] = places[7];
	places[23].setUp("Indianna Avenue", 23, places[23]);
	places[24].setUp("Illinois Avenue", 24, places[24]);
	places[25].setUp("B & O Railroad", 25, places[25]);
	places[26].setUp("Atlantic Avenue", 26, places[26]);
	places[27].setUp("Vermont Avenue", 27, places[27]);
	places[28].setUp("Water Works", 28, places[28]);
	places[29].setUp("Marvin Gardens", 29, places[29]);
	places[30].setUp("GO TO JAIL", 30, places[30]);
	places[31].setUp("Pacific Avenue", 31, places[31]);
	places[32].setUp("North Carolina Avenue", 32, places[32]);
	places[33] = places[2];
	places[34].setUp("Pennsylvania Avenue", 34, places[34]);
	places[35].setUp("Short Line", 35, places[35]);
	places[36] = places[7];
	places[37].setUp("Park Place", 37, places[37]);
	places[38].setUp("Luxury Tax", 38, places[38]);
	places[39].setUp("Boardwalk", 39, places[39]);
	//Finish other places
}
