#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>

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
	int priceBuy;
	int priceLand;
	char owned;
	void setUp(string x, int placex, int priceB, int priceL);
	
}; 
Place places[40];

void Place::setUp(string x, int placex, int priceB, int priceL)
{
	name = x;
	places[placex] = *this;
	owned = 'n';
	priceBuy = priceB;
	priceLand = priceL;
}

void setUp();
void communityChest(bool player);
void chance(bool player);

int main()
{
	setUp();
	srand(time(NULL));

	cout << "Welcome!\n";
	int dieRoll;
	int dieRoll2;
	string continueq;
	while((playerMoney > 0 && compMoney > 0) && (continueq != "n" && continueq != "no"))
	{
		if(playerJailTurns <= 0)
		{
			dieRoll = rand() % 6 + 1;
			dieRoll2 = rand() % 6 + 1;
			cout << "You rolled a " << dieRoll + dieRoll2 << endl;
			playerBoardP += dieRoll + dieRoll2;
			if(playerBoardP > 39)
			{
				cout << "You passed GO! Collect $200!\n";
				playerBoardP %= 40;
				playerMoney += 200;
			}
			cout << "You landed on: " << places[playerBoardP].name << endl;

			if(places[playerBoardP].priceBuy == 0)
			{
				if(places[playerBoardP].name == "Community Chest")
				{
					communityChest(true);
				}
				else if(places[playerBoardP].name == "Chance")
				{
					chance(true);
				}
				else if(places[playerBoardP].name == "Income Tax")
				{
					cout << "You need to pay $200 for Income Tax\n";
					playerMoney -= 200;
				}
				else if(places[playerBoardP].name == "GO TO JAIL")
				{
					cout << "GO TO JAIL. DO NOT PASS GO!\n";
					playerJailTurns = 2;
					playerBoardP = 10;
				}
				else if(places[playerBoardP].name == "Luxury Tax")
				{
					cout << "You need to pay $75 for Luxury Tax\n";
					playerMoney -= 75;
				}
			}
			else if(places[playerBoardP].owned == 'n')
			{
				string answer;
				cout << "Would you like to buy " <<  places[playerBoardP].name << "?: ";
				cin >> answer;
				if(answer[0] == 'y')
				{
					if(playerMoney -= places[playerBoardP].priceBuy < 0)
						cout << "You don't have enough money to buy" << places[playerBoardP].name <<"!\n";
					else
					{
						cout << "You now own " << places[playerBoardP].name << "!\n";
						places[playerBoardP].owned = 'p';
						playerMoney -= places[playerBoardP].priceBuy;
					}
				}
				else
				{
					cout << "You chose not to buy " << places[playerBoardP].name << endl;
				}
			}
			else if(places[playerBoardP].owned == 'p')
			{
				cout << "You already own " << places[playerBoardP].name << endl;
			}
			else //if(places[playerBoardP].owned == 'c')
			{
				cout << "You have to pay $" << places[playerBoardP].priceLand << " to the computer.\n";
				playerMoney -= places[playerBoardP].priceLand;
				compMoney += places[playerBoardP].priceLand;
			}
		}
		else
		{
			playerJailTurns--;
			cout << "You have " << playerJailTurns << " turns in jail left\n";
		}




		if(compJailTurns <= 0)
		{
			dieRoll = rand() % 6 + 1;
			dieRoll2 = rand() % 6 + 1;
			cout << "The computer rolled a " << dieRoll + dieRoll2 << endl;
			compBoardP += dieRoll + dieRoll2;
			if(compBoardP > 39)
			{
				cout << "The computer passed GO! The computer collects $200!\n";
				compBoardP %= 40;
				compMoney += 200;
			}
			cout << "The computer landed on: " << places[compBoardP].name << endl;

			if(places[compBoardP].priceBuy == 0)
			{
				if(places[compBoardP].name == "Comunity Chest")
				{
					communityChest(false);
				}
				else if(places[compBoardP].name == "Chance")
				{
					chance(false);
				}
				else if(places[compBoardP].name == "Income Tax")
				{
					cout << "The computer needs to pay $200 for Income Tax\n";
					compMoney -= 200;
				}
				else if(places[compBoardP].name == "GO TO JAIL")
				{
					cout << "The computer needs to: GO TO JAIL. DO NOT PASS GO!\n";
					compJailTurns = 2;
					compBoardP = 10;
				}
				else if(places[compBoardP].name == "Luxury Tax")
				{
					cout << "The computer needs to pay $75 for Luxury Tax\n";
					compMoney -= 75;
				}
			}
			else if(places[compBoardP].owned == 'n')
			{
				if(true)
				{
					if(compMoney -= places[compBoardP].priceBuy < 0)
						cout << "The computer does not have enough money to buy " << places[compBoardP].name << endl;
					else
					{
						cout << "The computer bought " << places[compBoardP].name << "!\n";
						places[compBoardP].owned = 'c';
						compMoney -= places[compBoardP].priceBuy;
					}
				}
				else
				{
					//for later AI
					cout << "The computer chose not to buy " << places[compBoardP].name << endl;
				}
			}
			else if(places[compBoardP].owned == 'c')
			{
				cout << "The computer already owns " << places[compBoardP].name << endl;
			}
			else //if(places[compBoardP].owned == 'p')
			{
				cout << "The computer has to pay $" << places[compBoardP].priceLand << " to you!\n";
				compMoney -= places[compBoardP].priceLand;
				playerMoney += places[compBoardP].priceLand;
			}
		}
		else
		{
			compJailTurns--;
			cout << "The computer has " << compJailTurns << " turns in jail left\n";
		}


		if(playerMoney < 0)
			playerMoney = 0;
		if(compMoney < 0)
			compMoney = 0;

		cout << "Player Money: $" << playerMoney << endl;
		cout << "Computer Money: $" << compMoney << endl;


		cout << "Continue?: ";
		cin >> continueq;
		
		cout << "--------------------------------------------------------------------------------";
	}

	cout << "Final Score: \n";
	if(playerMoney > compMoney)
	{
		cout << "#1 - Player: $" << playerMoney << endl;
		cout << "#2 - Computer: $" << compMoney << endl;
	}
	else
	{
		cout << "#1 - Computer: $" << compMoney << endl;
		cout << "#2 - Player: $" << playerMoney << endl;
	}


	if(continueq[0] == 'n' || playerMoney <= 0)
		cout << "Good Game! Sorry you had to lose";
	else
		cout << "Good Game! You Won!";

	if(continueq[0] == 'n')
		cout << " because your forfeited\n";
	else
		cout << endl;

	
	
	return 0;
}

void setUp()
{
	places[0].setUp("Start", 0, 0, -200);
	places[1].setUp("Mediterranean Avenue", 1, 60, 2);
	places[2].setUp("Community Chest", 2, 0, 0);
	places[3].setUp("Baltic Avenue", 3, 100, 4);
	places[4].setUp("Income Tax", 4, 0, 200);
	places[5].setUp("Reading Railroad", 5, 200, 25);
	places[6].setUp("Oriental Avenue", 6, 100, 6);
	places[7].setUp("Chance", 7, 0, 0);
	places[8].setUp("Vermont Avenue", 8, 100, 6);
	places[9].setUp("Connecticut Avenue", 9, 120, 8);
	places[10].setUp("Just Visiting (the Jail)", 10, 0, 0);
	places[11].setUp("St. Charles Place", 11, 140, 10);
	places[12].setUp("Electric Company", 12, 150, 11);
	places[13].setUp("States Avenue", 13, 140, 10);
	places[14].setUp("Virginia Avenue", 14, 160, 12);
	places[15].setUp("Pennsylvania Railroad", 15, 200, 25);
	places[16].setUp("St. James Place", 16, 180, 14);
	places[17] = places[2];
	places[18].setUp("Tennessee Avenue", 18, 180, 14);
	places[19].setUp("New York Avenue", 19, 200, 16);
	places[20].setUp("Free Parking", 20, 0, 0);
	places[21].setUp("Kentucky Avenue", 21, 220, 18);
	places[22] = places[7];
	places[23].setUp("Indiana Avenue", 23, 220, 18);
	places[24].setUp("Illinois Avenue", 24, 240, 20);
	places[25].setUp("B & O Railroad", 25, 200, 25);
	places[26].setUp("Atlantic Avenue", 26, 260, 22);
	places[27].setUp("Ventnor Avenue", 27, 260, 22);
	places[28].setUp("Water Works", 28, 150, 11);
	places[29].setUp("Marvin Gardens", 29, 280, 24);
	places[30].setUp("GO TO JAIL", 30, 0, 0);
	places[31].setUp("Pacific Avenue", 31, 300, 26);
	places[32].setUp("North Carolina Avenue", 32, 300, 26);
	places[33] = places[2];
	places[34].setUp("Pennsylvania Avenue", 34, 320, 28);
	places[35].setUp("Short Line", 35, 200, 25);
	places[36] = places[7];
	places[37].setUp("Park Place", 37, 350, 35);
	places[38].setUp("Luxury Tax", 38, 0, 75);
	places[39].setUp("Boardwalk", 39, 400, 50);
	//Finish other places
}

void communityChest(bool player)
{
	cout << "Setting Up. ";
	if(player)
	{
		cout << "You get";
		playerMoney += 100;
	}
	else
	{
		cout << "The computer gets";
		compMoney += 100;
	}
	cout << " $100 for compenstaion. Sorry for the Inconvenience... \n";
}

void chance(bool player)
{
	cout << "Setting Up. ";
	if(player)
	{
		cout << "You get";
		playerMoney += 100;
	}
	else
	{
		cout << "The computer gets";
		compMoney += 100;
	}
	cout << " $100 for compenstaion. Sorry for the Inconvenience... \n";
}
