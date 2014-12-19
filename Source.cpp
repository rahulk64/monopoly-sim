/*TO DO:
--make computer's chance and community chest cards point at computer, not player
--Make GET OUT OF JAIL FREE card work
--do case 13 of Community Chest Switch and other repairs
--fix colonization prices with actual monopoly set
*/


#include<iostream>
#include<ctime>
#include<cstdio>
#include<string>

using namespace std;

int prize; //community chest and chance

int playerMoney = 2500;
int computerMoney = 2500;
int boardPlace = 0;
int computerPlace = 0;
string place;
string CPUplace;
int playerJailTurns = 0;
int computerJailTurns = 0;
char yn2;

void medAvenue();
char Medavenue = 'e';
void communityChest();
void balticAvenue();
char Balticavenue = 'e';
void incomeTax();
void readingRailroad();
char Readingrailroad = 'e';
void orientalAvenue();
char Orientalavenue = 'e';
void chance();
void vermontAvenue();
char Vermontavenue= 'e';
void conneAvenue();
char Conneavenue = 'e';
void charlesPlace();
char Charlesplace = 'e';
void elctricCompany();
char Electriccompany = 'e';
void statesAvenue();
char Statesavenue = 'e';
void virginiaAvenue();
char Virginiaavenue = 'e';
void pennRailroad();
char Pennrailroad = 'e';
void jamesPlace();
char Jamesplace = 'e';
void tennAvenue();
char Tennavenue = 'e';
void nyAvenue();
char NYavenue = 'e';
void kentuckyAvenue();
char Kentuckyavenue ='e';
void indianaAvenue();
char Indianaavenue = 'e';
void illinoisAvenue();
char Illinoisavenue = 'e';
void boRailroad();
char BOrailroad = 'e';
void atlanticAvenue();
char Atlanticavenue = 'e';
void ventnorAvenue();
char Ventnoravenue = 'e';
void waterWorks();
char Waterworks = 'e';
void marvinGardens();
char Marvingardens = 'e';
void pacificAvenue();
char Pacificavenue = 'e';
void ncAvenue();
char NCavenue = 'e';
void pennAvenue();
char Pennavenue = 'e';
void shortLine();
char Shortline = 'e';
void parkPlace();
char Parkplace = 'e';
void luxuryTax();
void broadway();
char Broadway = 'e';

int dieRoller();
void checkPlace();
void computerRoll();

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	prize = (rand() % 18) + 1;
	cout << "Welcome to Monopoly!" << endl;

	string continueq;

	do
	{
		if (playerJailTurns > 0)
		{
			playerJailTurns--;
			cout << "You have " << playerJailTurns << " turn(s) left in jail\n";
			place = "Oh No! JAIL!";
			boardPlace = 10;
		}
		else
		{
			int die = dieRoller();
			cout << "You rolled a " << die << endl;
			boardPlace += die;

			if(boardPlace > 39)
			{
				boardPlace = (boardPlace % 40);
				playerMoney +=200;
				cout << "You collect $200 as you pass GO!\n";
			}
			
			checkPlace();
	}

		cout << "Continue? (yes/no): ";
		cin >> continueq;
		if(continueq == "no")
			break;

		if (computerJailTurns > 0)
		{
			--computerJailTurns;
			cout << "The computer has " << computerJailTurns << " turn(s) in jail left\n";
			CPUplace = "Oh Yay! Jail!";
			computerPlace = 10;
		}
		else
			computerRoll();

		cout << "You have $" << playerMoney << endl;
		cout << "The computer has $" << computerMoney << endl;

		cout << "Continue? (yes/no): ";
		cin >> continueq; 
	} while(continueq != "no" &&(playerMoney >= 0 && computerMoney >= 0));

	cout << "You ended with $" << playerMoney << endl;
	cout << "The computer ended with $" << computerMoney << endl;
	return 0;
}

int dieRoller()
{
	srand(static_cast<unsigned int>(time(0)));

	int randomNumber = rand();

	int die = (randomNumber % 6) + 1;

	return die;
}

void checkPlace()
{
	switch(boardPlace)
	{
		case 0: place = "Start";
			cout << "You have landed on: " << place << endl;
			break;
		case 1: place = "Medeteranian Avenue"; 
			cout << "You have landed on: " << place << endl;
			medAvenue();
			break;
		case 2: place = "Community Chest"; 
			cout << "You have landed on: " << place << endl;
			communityChest();
			break;
		case 3: place = "Baltic Avenue";
			cout << "You have landed on: " << place << endl;
			balticAvenue();
			break;
		case 4: place = "Income Tax";
			cout << "You have landed on: " << place << endl;
			incomeTax();
			break;
		case 5: place = "Reading Railroad";
			cout << "You have landed on: " << place << endl;
			readingRailroad();
			break;
		case 6: place = "Oriental Avenue";
			cout << "You have landed on: " << place << endl;
			orientalAvenue();
			break;
		case 7: place = "Chance";
			cout << "You have landed on: " << place << endl;
			chance();
			break;
		case 8: place = "Vermont Avenue";
			cout << "You have landed on: " << place << endl;
			vermontAvenue();
			break;
		case 9: place = "Connectuit Avenue";
			cout << "You have landed on: " << place << endl;
			conneAvenue();
			break;
		case 10: place = "Just Visiting";
			cout << "You have landed on: " << place << endl;
			break;
		case 11: place = "St. Charles Place";
			cout << "You have landed on: " << place << endl;
			charlesPlace();
			break;
		case 12: place = "Electric Company";
			cout << "You have landed on: " << place << endl;
			elctricCompany();
			break;
		case 13: place = "States Avenue";
			cout << "You have landed on: " << place << endl;
			statesAvenue();
			break;
		case 14: place = "Virginina Avenue";
			cout << "You have landed on: " << place << endl;
			virginiaAvenue();
			break;
		case 15: place = "Pennsylvania Railroad";
			cout << "You have landed on: " << place << endl;
			pennRailroad();
			break;
		case 16: place = "St. James Place";
			cout << "You have landed on: " << place << endl;
			jamesPlace();
			break;
		case 17: place = "Community Chest";
			cout << "You have landed on: " << place << endl;
			communityChest();
			break;
		case 18: place = "Tennesse Avenue";
			cout << "You have landed on: " << place << endl;
			tennAvenue();
			break;
		case 19: place = "New York Avenue";
			cout << "You have landed on: " << place << endl;
			nyAvenue();
			break;
		case 20: place = "Free Parking";
			cout << "You have landed on: " << place << endl;
			break;
		case 21: place = "Kentucky Avenue";
			cout << "You have landed on: " << place << endl;
			kentuckyAvenue();
			break;
		case 22: place = "Chance";
			cout << "You have landed on: " << place << endl;
			chance();
			break;
		case 23: place = "Indiana Aavenue";
			cout << "You have landed on: " << place << endl;
			indianaAvenue();
			break;
		case 24: place = "Illinois Avenue";
			cout << "You have landed on: " << place << endl;
			illinoisAvenue();
			break;
		case 25: place = "B&O Railroad";
			cout << "You have landed on: " << place << endl;
			boRailroad();
			break;
		case 26: place = "Atlantic Avenue";
			cout << "You have landed on: " << place << endl;
			atlanticAvenue();
			break;
		case 27: place = "Ventnor Avenue";
			cout << "You have landed on: " << place << endl;
			ventnorAvenue();
			break;
		case 28: place = "Water Works";
			cout << "You have landed on: " << place << endl;
			waterWorks();
			break;
		case 29: place = "Marvin Gardens";
			cout << "You have landed on: " << place << endl;
			marvinGardens();
			break;
		case 30: place = "Jail";
			cout << "Oh No! You're in jail!\n";
			playerJailTurns = 2;
			break;
		case 31: place = "Pacific Avenue";
			cout << "You have landed on: " << place << endl;
			pacificAvenue();
			break;
		case 32: place = "North Carolina Avenue";
			cout << "You have landed on: " << place << endl;
			ncAvenue();
			break;
		case 33: place = "Community Chest";
			cout << "You have landed on: " << place << endl;
			communityChest();
			break;
		case 34: place = "Pennsylvania Avenue";
			cout << "You have landed on: " << place << endl;
			pennAvenue();
			break;
		case 35: place = "Short Line";
			cout << "You have landed on: " << place << endl;
			shortLine();
			break;
		case 36: place = "Chance";
			cout << "You have landed on: " << place << endl;
			chance();
			break;
		case 37: place = "Park Place";
			cout << "You have landed on: " << place << endl;
			parkPlace();
			break;
		case 38: place = "Luxury Tax";
			cout << "You have landed on: " << place << endl;
			luxuryTax();
			break;
		case 39: place = "Broadway";
			cout << "You have landed on: " << place << endl;
			broadway();
			break;
		default: cout << "You have an error in the program. Please report this error." << endl;
			place = "Outside the Monopoly Board!";
			break;
	}

}

void computerRoll()
{
	srand(static_cast<unsigned int>(time(0)));

	int randomNum = rand();

	int dice = (randomNum % 6) + 1;

	cout << "The computer rolled a " << dice << endl;
	computerPlace += dice;

	if(computerPlace > 39)
	{
		computerPlace = (computerPlace % 40);
		computerMoney +=200;
		cout << "The computer collects $200 for passing GO!\n";
	}
	
	switch(computerPlace)
	{
		case 0: CPUplace = "Start";
			break;
		case 1: CPUplace = "Medeteranian Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Medavenue == 'u')
			{
				cout << "The computer has to pay you $60 since you own " << CPUplace << endl;
				computerMoney -= 60;
				playerMoney += 60;
			}
			else if(Medavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Medavenue = 'c';
				computerMoney -= 60;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 2: CPUplace = "Community Chest";
			cout << "The computer landed on " << CPUplace << endl;
			prize++;
			switch (prize)
			{
			case 1: cout << "Advance to GO! Computer collect $200!\n";
				place = "Start";
				boardPlace = 0;
				computerMoney += 200;
				break;
			case 2: cout << "Bank error in computer's favor. Computer collects $75\n";
				computerMoney += 75;
				break;
			case 3: cout << "Doctor's Fees. Computer pays $50\n";
				computerMoney -=50;
				break;
			case 4: cout << "Computer has a Get Out of Jail Free Card!\n";
				break;
			case 5: cout << "GO TO JAIL\n";
				place = "Oh No! Jail!\n";
				computerJailTurns = 2;
				break;
			case 6: cout << "It is your birthday! Collect $10 from the computer!\n";
				playerMoney +=10;
				computerMoney -= 10;
				break;
			case 7: cout << "It is Grand Opera Night! Collect $50 from the computer!\n";
				playerMoney +=50;
				computerMoney -=50;
				break;
			case 8: cout << "Incont Tax Refund. You gain $20\n";
				playerMoney += 20;
				break;
			case 9: cout << "Life Insurance matures! Gain $100\n";
				playerMoney += 100;
				break;
			case 10: cout << "Pay hospital fees of $100\n";
				playerMoney -= 100;
				break;
			case 11: cout << "Pay school fees of $50\n";
				playerMoney -= 50;
				break;
			case 12: cout << "Receive $25 Consultancy Fee\n";
				playerMoney += 25;
				break;
			case 13: cout << "You are assessed for street repairs for every place you colonized.\n";
				break;
			case 14: cout << "You have won 2nd Place in a Beauty Contest! You get $10\n";
				playerMoney += 10;
				break;
			case 15: cout << "You inherit $100\n";
				playerMoney += 100;
				break;
			case 16: cout << "From Sale of Stock, you get $50\n";
				playerMoney += 50;
				break;
			case 17: cout << "Holiday Fund Matress. Recieve $100\n";
				playerMoney += 100;
				break;
			case 18: cout << "You receive a telegram from your Aunt Betsy wishing you the best of luck. You gain $25\n";
				playerMoney += 25;
				prize = 0;
				break;
			default: cout << "Your game crashed or has a bug in it.\n";
			}
			break;
		case 3: CPUplace = "Baltic Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Balticavenue == 'u')
			{
				cout << "The computer has to pay you $60 since you own " << CPUplace << endl;
				computerMoney -= 60;
				playerMoney += 60;
			}
			else if(Balticavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Balticavenue = 'c';
				computerMoney -= 60;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 4: CPUplace = "Income Tax";
			cout << "The computer landed on " << CPUplace << endl;
			cout << "The computer has to pay $200 to the bank.\n";
			computerMoney -= 200;
			break;
		case 5: CPUplace = "Reading Railroad";
			cout << "The computer landed on " << CPUplace << endl;
			if(Readingrailroad == 'u')
			{
				cout << "The computer has to pay you $100 since you own " << CPUplace << endl;
				computerMoney -= 100;
				playerMoney += 100;
			}
			else if(Readingrailroad != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Readingrailroad = 'c';
				computerMoney -= 200;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 6: CPUplace = "Oriental Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Orientalavenue == 'u')
			{
				cout << "The computer has to pay you $100 since you own " << CPUplace << endl;
				computerMoney -= 100;
				playerMoney += 100;
			}
			else if(Orientalavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Orientalavenue = 'c';
				computerMoney -= 100;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 7: CPUplace = "Chance";
			cout << "The computer landed on " << CPUplace << endl;
			prize++;
			switch (prize)
			{
			case 1: cout << "Advance to GO! Collect $200!\n";
				place = "Start";
				boardPlace = 0;
				playerMoney += 200;
				break;
			case 2: cout << "Bank error in your favor. Collect $75\n";
				playerMoney += 75;
				break;
			case 3: cout << "Doctor's Fees. Pay $50\n";
				playerMoney -=50;
				break;
			case 4: cout << "You have a Get Out of Jail Free Card!\n";
				break;
			case 5: cout << "GO TO JAIL\n";
				place = "Oh No! Jail!\n";
				playerJailTurns = 2;
				break;
			case 6: cout << "It is your birthday! Collect $10 from the computer!\n";
				playerMoney +=10;
				computerMoney -= 10;
				break;
			case 7: cout << "It is Grand Opera Night! Collect $50 from the computer!\n";
				playerMoney +=50;
				computerMoney -=50;
				break;
			case 8: cout << "Incont Tax Refund. You gain $20\n";
				playerMoney += 20;
				break;
			case 9: cout << "Life Insurance matures! Gain $100\n";
				playerMoney += 100;
				break;
			case 10: cout << "Pay hospital fees of $100\n";
				playerMoney -= 100;
				break;
			case 11: cout << "Pay school fees of $50\n";
				playerMoney -= 50;
				break;
			case 12: cout << "Receive $25 Consultancy Fee\n";
				playerMoney += 25;
				break;
			case 13: cout << "You are assessed for street repairs for every place you colonized.\n";
				break;
			case 14: cout << "You have won 2nd Place in a Beauty Contest! You get $10\n";
				playerMoney += 10;
				break;
			case 15: cout << "You inherit $100\n";
				playerMoney += 100;
				break;
			case 16: cout << "From Sale of Stock, you get $50\n";
				playerMoney += 50;
				break;
			case 17: cout << "Holiday Fund Matress. Recieve $100\n";
				playerMoney += 100;
				break;
			case 18: cout << "You receive a telegram from your Aunt Betsy wishing you the best of luck. You gain $25\n";
				playerMoney += 25;
				prize = 0;
				break;
			default: cout << "Your game crashed or has a bug in it.\n";
			}
			break;
		case 8: CPUplace = "Vermont Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Vermontavenue == 'u')
			{
				cout << "The computer has to pay you $100 since you own " << CPUplace << endl;
				computerMoney -= 100;
				playerMoney += 100;
			}
			else if(Vermontavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Vermontavenue = 'c';
				computerMoney -= 100;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 9: CPUplace = "Connectuit Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Conneavenue == 'u')
			{
				cout << "The computer has to pay you $120 since you own " << CPUplace << endl;
				computerMoney -= 120;
				playerMoney += 120;
			}
			else if(Conneavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Conneavenue = 'c';
				computerMoney -= 120;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 10: CPUplace = "Just Visiting";
			cout << "The computer landed on " << CPUplace << endl;
			break;
		case 11: CPUplace = "St. Charles Place";
			cout << "The computer landed on " << CPUplace << endl;
			if(Charlesplace == 'u')
			{
				cout << "The computer has to pay you $140 since you own " << CPUplace << endl;
				computerMoney -= 140;
				playerMoney += 140;
			}
			else if(Charlesplace != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Charlesplace = 'c';
				computerMoney -= 140;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 12: CPUplace = "Electric Company";
			cout << "The computer landed on " << CPUplace << endl;
			if(Electriccompany == 'u')
			{
				cout << "The computer has to pay you $75 since you own " << CPUplace << endl;
				computerMoney -= 75;
				playerMoney += 75;
			}
			else if(Electriccompany != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Electriccompany = 'c';
				computerMoney -= 150;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 13: CPUplace = "States Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Statesavenue == 'u')
			{
				cout << "The computer has to pay you $140 since you own " << CPUplace << endl;
				computerMoney -= 140;
				playerMoney += 140;
			}
			else if(Statesavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Statesavenue = 'c';
				computerMoney -= 140;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 14: CPUplace = "Virginina Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Virginiaavenue == 'u')
			{
				cout << "The computer has to pay you $160 since you own " << CPUplace << endl;
				computerMoney -= 160;
				playerMoney += 160;
			}
			else if(Virginiaavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Virginiaavenue = 'c';
				computerMoney -= 160;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 15: CPUplace = "Pennsylvania Railroad";
			cout << "The computer landed on " << CPUplace << endl;
			if(Pennrailroad == 'u')
			{
				cout << "The computer has to pay you $100 since you own " << CPUplace << endl;
				computerMoney -= 100;
				playerMoney += 100;
			}
			else if(Pennrailroad != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Pennrailroad = 'c';
				computerMoney -= 200;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 16: CPUplace = "St. James Place";
			cout << "The computer landed on " << CPUplace << endl;
			if(Jamesplace == 'u')
			{
				cout << "The computer has to pay you $180 since you own " << CPUplace << endl;
				computerMoney -= 180;
				playerMoney += 180;
			}
			else if(Jamesplace != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Jamesplace = 'c';
				computerMoney -= 180;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 17: CPUplace = "Community Chest";
			cout << "The computer landed on " << CPUplace << endl;
			break;
		case 18: CPUplace = "Tennesse Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Tennavenue == 'u')
			{
				cout << "The computer has to pay you $180 since you own " << CPUplace << endl;
				computerMoney -= 180;
				playerMoney += 180;
			}
			else if(Tennavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Tennavenue = 'c';
				computerMoney -= 180;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 19: CPUplace = "New York Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(NYavenue == 'u')
			{
				cout << "The computer has to pay you $200 since you own " << CPUplace << endl;
				computerMoney -= 200;
				playerMoney += 200;
			}
			else if(NYavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Tennavenue = 'c';
				computerMoney -= 200;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 20: CPUplace = "Free Parking";
			cout << "The computer landed on " << CPUplace << endl;
			break;
		case 21: CPUplace = "Kentucky Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Kentuckyavenue == 'u')
			{
				cout << "The computer has to pay you $220 since you own " << CPUplace << endl;
				computerMoney -= 220;
				playerMoney += 220;
			}
			else if(Kentuckyavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Kentuckyavenue = 'c';
				computerMoney -= 220;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 22: CPUplace = "Chance";
			cout << "The computer landed on " << CPUplace << endl;
			break;
		case 23: CPUplace = "Indiana Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Indianaavenue == 'u')
			{
				cout << "The computer has to pay you $220 since you own " << CPUplace << endl;
				computerMoney -= 220;
				playerMoney += 220;
			}
			else if(Indianaavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Indianaavenue = 'c';
				computerMoney -= 220;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 24: CPUplace = "Illinois Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Illinoisavenue == 'u')
			{
				cout << "The computer has to pay you $240 since you own " << CPUplace << endl;
				computerMoney -= 240;
				playerMoney += 240;
			}
			else if(Illinoisavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Illinoisavenue = 'c';
				computerMoney -= 240;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 25: CPUplace = "B&O Railroad";
			cout << "The computer landed on " << CPUplace << endl;
			if(BOrailroad == 'u')
			{
				cout << "The computer has to pay you $100 since you own " << CPUplace << endl;
				computerMoney -= 100;
				playerMoney += 100;
			}
			else if(BOrailroad != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				BOrailroad = 'c';
				computerMoney -= 200;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 26: CPUplace = "Atlantic Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Atlanticavenue == 'u')
			{
				cout << "The computer has to pay you $260 since you own " << CPUplace << endl;
				computerMoney -= 260;
				playerMoney += 260;
			}
			else if(Atlanticavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Atlanticavenue = 'c';
				computerMoney -= 260;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 27: CPUplace = "Ventnor Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Ventnoravenue == 'u')
			{
				cout << "The computer has to pay you $260 since you own " << CPUplace << endl;
				computerMoney -= 260;
				playerMoney += 260;
			}
			else if(Ventnoravenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Ventnoravenue = 'c';
				computerMoney -= 260;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 28: CPUplace = "Water Works";
			cout << "The computer landed on " << CPUplace << endl;
			if(Waterworks == 'u')
			{
				cout << "The computer has to pay you $75 since you own " << CPUplace << endl;
				computerMoney -= 75;
				playerMoney += 75;
			}
			else if(Waterworks != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Waterworks = 'c';
				computerMoney -= 150;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 29: CPUplace = "Marvin Gardens";
			cout << "The computer landed on " << CPUplace << endl;
			if(Marvingardens == 'u')
			{
				cout << "The computer has to pay you $280 since you own " << CPUplace << endl;
				computerMoney -= 280;
				playerMoney += 280;
			}
			else if(Marvingardens != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Marvingardens = 'c';
				computerMoney -= 280;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 30: CPUplace = "Jail";
			computerJailTurns = 2;
			cout << "The computer is in jail!\n";
			
			break;
		case 31: CPUplace = "Pacific Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Pacificavenue == 'u')
			{
				cout << "The computer has to pay you $300 since you own " << CPUplace << endl;
				computerMoney -= 300;
				playerMoney += 300;
			}
			else if(Pacificavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Pacificavenue = 'c';
				computerMoney -= 300;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 32: CPUplace = "North Carolina Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(NCavenue == 'u')
			{
				cout << "The computer has to pay you $300 since you own " << CPUplace << endl;
				computerMoney -= 300;
				playerMoney += 300;
			}
			else if(NCavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				NCavenue = 'c';
				computerMoney -= 300;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 33: CPUplace = "Community Chest";
			cout << "The computer landed on " << CPUplace << endl;
			break;
		case 34: CPUplace = "Pennsylvania Avenue";
			cout << "The computer landed on " << CPUplace << endl;
			if(Pennavenue == 'u')
			{
				cout << "The computer has to pay you $320 since you own " << CPUplace << endl;
				computerMoney -= 320;
				playerMoney += 320;
			}
			else if(Pennavenue != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Pennavenue = 'c';
				computerMoney -= 320;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 35: CPUplace = "Short Line";
			cout << "The computer landed on " << CPUplace << endl;
			if(Shortline == 'u')
			{
				cout << "The computer has to pay you $100 since you own " << CPUplace << endl;
				computerMoney -= 100;
				playerMoney += 100;
			}
			else if(Shortline != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Shortline = 'c';
				computerMoney -= 200;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 36: CPUplace = "Chance";
			cout << "The computer landed on " << CPUplace << endl;
			break;
		case 37: CPUplace = "Park Place";
			cout << "The computer landed on " << CPUplace << endl;
			if(Parkplace == 'u')
			{
				cout << "The computer has to pay you $350 since you own " << CPUplace << endl;
				computerMoney -= 350;
				playerMoney += 350;
			}
			else if(Parkplace != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Parkplace = 'c';
				computerMoney -= 350;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		case 38: CPUplace = "Luxury Tax";
			cout << "The computer landed on " << CPUplace << endl;
			computerMoney -= 75;
			cout << "The computer has to pay $75\n";
			break;
		case 39: CPUplace = "Broadway";
			cout << "The computer landed on " << CPUplace << endl;
			if(Broadway == 'u')
			{
				cout << "The computer has to pay you $400 since you own " << CPUplace << endl;
				computerMoney -= 400;
				playerMoney += 400;
			}
			else if(Broadway != 'c')
			{
				cout << "The computer is colonizing " << CPUplace << endl;
				Broadway = 'c';
				computerMoney -= 500;
			}
			else
				cout << "The computer already owns " << CPUplace << endl;
			break;
		default: cout << "You have an error in the program. Please report this error." << endl;
			place = "Outside the Monopoly Board!";
			break;

		
	}
	
}

void medAvenue()
{
	if(Medavenue == 'c')
	{
		cout << "You have to pay $60 to the computer\n";
		playerMoney -= 60;
		computerMoney += 60;
	}
	else if (Medavenue != 'u')
	{
		cout << "Would you like to colonize Medeteranian Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 60)
		{
			Medavenue = 'u';
			playerMoney -= 60;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You own Medeteranian Avenue.\n";
}
void communityChest()
{
	prize++;
	switch (prize)
	{
	case 1: cout << "Advance to GO! Collect $200!\n";
		place = "Start";
		boardPlace = 0;
		playerMoney += 200;
		break;
	case 2: cout << "Bank error in your favor. Collect $75\n";
		playerMoney += 75;
		break;
	case 3: cout << "Doctor's Fees. Pay $50\n";
		playerMoney -=50;
		break;
	case 4: cout << "You have a Get Out of Jail Free Card!\n";
		break;
	case 5: cout << "GO TO JAIL\n";
		place = "Oh No! Jail!\n";
		playerJailTurns = 2;
		break;
	case 6: cout << "It is your birthday! Collect $10 from the computer!\n";
		playerMoney +=10;
		computerMoney -= 10;
		break;
	case 7: cout << "It is Grand Opera Night! Collect $50 from the computer!\n";
		playerMoney +=50;
		computerMoney -=50;
		break;
	case 8: cout << "Incont Tax Refund. You gain $20\n";
		playerMoney += 20;
		break;
	case 9: cout << "Life Insurance matures! Gain $100\n";
		playerMoney += 100;
		break;
	case 10: cout << "Pay hospital fees of $100\n";
		playerMoney -= 100;
		break;
	case 11: cout << "Pay school fees of $50\n";
		playerMoney -= 50;
		break;
	case 12: cout << "Receive $25 Consultancy Fee\n";
		playerMoney += 25;
		break;
	case 13: cout << "You are assessed for street repairs for every place you colonized.\n";
		break;
	case 14: cout << "You have won 2nd Place in a Beauty Contest! You get $10\n";
		playerMoney += 10;
		break;
	case 15: cout << "You inherit $100\n";
		playerMoney += 100;
		break;
	case 16: cout << "From Sale of Stock, you get $50\n";
		playerMoney += 50;
		break;
	case 17: cout << "Holiday Fund Matress. Recieve $100\n";
		playerMoney += 100;
		break;
	case 18: cout << "You receive a telegram from your Aunt Betsy wishing you the best of luck. You gain $25\n";
		playerMoney += 25;
		prize = 0;
		break;
	default: cout << "Your game crashed or has a bug in it.\n";
	}
}
void balticAvenue()
{
	if(Balticavenue == 'c')
	{
		cout << "You have to pay $60 to the computer\n";
		playerMoney -= 60;
		computerMoney += 60;
	}
	else if (Balticavenue != 'u')
	{
		cout << "Would you like to colonize Baltic Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 60)
		{
			Medavenue = 'u';
			playerMoney -=60;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Baltic Avenue.\n";
}
void incomeTax()
{
	cout << "You have to pay $200.\n";
	playerMoney -= 200;
}
void readingRailroad()
{
	if(Readingrailroad == 'c')
	{
		cout << "You have to pay $100 to the computer\n";
		playerMoney -= 100;
		computerMoney += 100;
	}
	else if (Readingrailroad != 'u')
	{
		cout << "Would you like to colonize Reading Railroad? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 200)
		{
			Readingrailroad = 'u';
			playerMoney -=200;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Reading Railroad.\n";
}
void orientalAvenue()
{
	if(Orientalavenue == 'c')
	{
		cout << "You have to pay $100 to the computer\n";
		playerMoney -= 100;
		computerMoney += 100;
	}
	else if (Orientalavenue != 'u')
	{
		cout << "Would you like to colonize Oriental Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 100)
		{
			Orientalavenue = 'u';
			playerMoney -=100;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Oriental Avenue.\n";
}
void chance()
{
	prize++;
	switch (prize)
	{
	case 1: cout << "Advance to GO! Collect $200!\n";
		place = "Start";
		boardPlace = 0;
		playerMoney += 200;
		break;
	case 2: cout << "Advance to Illinois Avenue\n";
		boardPlace = 16;
		place = "Illinois Avenue";
		break;
	case 3: cout << "Doctor's Fees. Pay $50\n";
		playerMoney -=50;
		break;
	case 4: cout << "You have a Get Out of Jail Free Card!\n";
		break;
	case 5: cout << "GO TO JAIL\n";
		place = "Oh No! Jail!\n";
		playerJailTurns = 2;
		break;
	case 6: cout << "Advance to St. Charles Place\n";
		boardPlace = 11;
		place = "St. Charles Place";
		break;
	case 7: cout << "Bank pays you a dividend of $50\n";
		playerMoney += 50;
		break;
	case 8: cout << "You get a GET OUT OF JAIL FREE card!\n";
		break;
	case 9: cout << "Go back 3 spaces\n";
		boardPlace -= 3;
		break;
	case 10: cout << "GO TO JAIL\n";
		boardPlace = 10;
		place = "Oh No! JAIL";
		break;
	case 11: cout << "Pay poor tax of $15\n";
		playerMoney -= 15;
		break;
	case 12: cout << "Take a trip to Reading Railroad!\n";
		place = "Reading Railroad";
		boardPlace = 5;
		break;
	case 13: cout << "Take a walk on Broadway\n";
		boardPlace = 39;
		place = "Broadway";
		break;
	case 14: cout << "You have been elected chairman of the board – pay the computer $50\n";
		playerMoney -= 50;
		computerMoney += 50;
		break;
	case 15: cout << "Your building loan matures – collect $150\n";
		playerMoney += 150;
		break;
	case 16: cout << "You have won a crossword competition - collect $100\n";
		break;
	case 17: cout << "Take a walk on Broadway\n";
		boardPlace = 39;
		place = "Broadway";
		break;
	case 18: cout << "Doctor's Fees. Pay $50\n";
		playerMoney -=50;
		prize = 0;
		break;
	default: cout << "Your game crashed or has a bug in it.\n";
	}
}
void vermontAvenue()
{
	if(Vermontavenue == 'c')
	{
		cout << "You have to pay $100 to the computer\n";
		playerMoney -= 100;
		computerMoney += 100;
	}
	else if (Vermontavenue != 'u')
	{
		cout << "Would you like to colonize Vermont Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 100)
		{
			Vermontavenue = 'u';
			playerMoney -=100;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Vermont Avenue.\n";
}
void conneAvenue()
{
	if(Conneavenue == 'c')
	{
		cout << "You have to pay $120 to the computer\n";
		playerMoney -= 120;
		computerMoney += 120;
	}
	else if (Conneavenue != 'u')
	{
		cout << "Would you like to colonize Conneticuit Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 120)
		{
			Conneavenue = 'u';
			playerMoney -=120;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Conneticuit Avenue.\n";
}
void charlesPlace()
{
	if(Charlesplace == 'c')
	{
		cout << "You have to pay $140 to the computer\n";
		playerMoney -= 140;
		computerMoney += 140;
	}
	else if (Charlesplace != 'u')
	{
		cout << "Would you like to colonize St. Charles Place? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 140)
		{
			Charlesplace = 'u';
			playerMoney -=140;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own St. Charles Place.\n";
}
void elctricCompany()
{
	if(Electriccompany == 'c')
	{
		cout << "You have to pay $75 to the computer\n";
		playerMoney -= 75;
		computerMoney += 75;
	}
	else if (Electriccompany != 'u')
	{
		cout << "Would you like to colonize Electric Company? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 150)
		{
			Electriccompany = 'u';
			playerMoney -=150;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Electric Company.\n";
}
void statesAvenue()
{
	if(Statesavenue == 'c')
	{
		cout << "You have to pay $140 to the computer\n";
		playerMoney -= 140;
		computerMoney += 140;
	}
	else if (Statesavenue != 'u')
	{
		cout << "Would you like to colonize States Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 140)
		{
			Statesavenue = 'u';
			playerMoney -=140;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own States Avenue.\n";
}
void virginiaAvenue()
{
	if(Virginiaavenue == 'c')
	{
		cout << "You have to pay $160 to the computer\n";
		playerMoney -= 160;
		computerMoney += 160;
	}
	else if (Virginiaavenue != 'u')
	{
		cout << "Would you like to colonize Virginia Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 160)
		{
			Virginiaavenue = 'u';
			playerMoney -=160;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Virginia Avenue.\n";
}
void pennRailroad()
{
	if(Pennrailroad == 'c')
	{
		cout << "You have to pay $100 to the computer\n";
		playerMoney -= 100;
		computerMoney += 100;
	}
	else if (Pennrailroad != 'u')
	{
		cout << "Would you like to colonize Pensylvania Railroad? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 200)
		{
			Pennrailroad = 'u';
			playerMoney -=200;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Pennsylvania Railroad.\n";
}
void jamesPlace()
{
	if(Jamesplace == 'c')
	{
		cout << "You have to pay $180 to the computer\n";
		playerMoney -= 180;
		computerMoney += 180;
	}
	else if (Jamesplace != 'u')
	{
		cout << "Would you like to colonize St. James Place? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 180)
		{
			Jamesplace = 'u';
			playerMoney -=180;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own St. James Place.\n";
}
void tennAvenue()
{
	if(Tennavenue == 'c')
	{
		cout << "You have to pay $180 to the computer\n";
		playerMoney -= 180;
		computerMoney += 180;
	}
	else if (Tennavenue != 'u')
	{
		cout << "Would you like to colonize Tenesse Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 180)
		{
			Tennavenue = 'u';
			playerMoney -=180;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Tenesse Avenue.\n";
}
void nyAvenue()
{
	if(NYavenue == 'c')
	{
		cout << "You have to pay $200 to the computer\n";
		playerMoney -= 200;
		computerMoney += 200;
	}
	else if (NYavenue != 'u')
	{
		cout << "Would you like to colonize New York Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 200)
		{
			NYavenue = 'u';
			playerMoney -=200;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own New York Avenue.\n";
}
void kentuckyAvenue()
{
	if(Kentuckyavenue == 'c')
	{
		cout << "You have to pay $220 to the computer\n";
		playerMoney -= 220;
		computerMoney += 220;
	}
	else if (Kentuckyavenue != 'u')
	{
		cout << "Would you like to colonize Kentucky Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 220)
		{
			Kentuckyavenue = 'u';
			playerMoney -=220;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Kentucky Avenue.\n";
}
void indianaAvenue()
{
	if(Indianaavenue == 'c')
	{
		cout << "You have to pay $220 to the computer\n";
		playerMoney -= 220;
		computerMoney += 220;
	}
	else if (Indianaavenue != 'u')
	{
		cout << "Would you like to colonize Indiana Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 220)
		{
			Indianaavenue = 'u';
			playerMoney -=220;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own States Avenue.\n";
}
void illinoisAvenue()
{
	if(Illinoisavenue == 'c')
	{
		cout << "You have to pay $240 to the computer\n";
		playerMoney -= 240;
		computerMoney += 240;
	}
	else if (Illinoisavenue != 'u')
	{
		cout << "Would you like to colonize Illinois Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 240)
		{
			Illinoisavenue = 'u';
			playerMoney -=240;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Illinois Avenue.\n";
}
void boRailroad()
{
	if(BOrailroad == 'c')
	{
		cout << "You have to pay $100 to the computer\n";
		playerMoney -= 100;
		computerMoney += 100;
	}
	else if (BOrailroad != 'u')
	{
		cout << "Would you like to colonize B&O Railroad? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 200)
		{
			BOrailroad = 'u';
			playerMoney -=200;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own B&O Railroad.\n";
}
void atlanticAvenue()
{
	if(Atlanticavenue == 'c')
	{
		cout << "You have to pay $260 to the computer\n";
		playerMoney -= 260;
		computerMoney += 260;
	}
	else if (Balticavenue != 'u')
	{
		cout << "Would you like to colonize Atlantic Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 260)
		{
			Atlanticavenue = 'u';
			playerMoney -=260;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Atlantic Avenue.\n";
}
void ventnorAvenue()
{
	if(Ventnoravenue == 'c')
	{
		cout << "You have to pay $260 to the computer\n";
		playerMoney -= 260;
		computerMoney += 260;
	}
	else if (Ventnoravenue != 'u')
	{
		cout << "Would you like to colonize Ventnor Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 260)
		{
			Ventnoravenue = 'u';
			playerMoney -=260;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Ventnor Avenue.\n";
}
void waterWorks()
{
	if(Waterworks == 'c')
	{
		cout << "You have to pay $75 to the computer\n";
		playerMoney -= 75;
		computerMoney += 75;
	}
	else if (Waterworks != 'u')
	{
		cout << "Would you like to colonize Water Works? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney > 150)
		{
			Waterworks = 'u';
			playerMoney -=150;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Water Works.\n";
}
void marvinGardens()
{
	if(Marvingardens == 'c')
	{
		cout << "You have to pay $280 to the computer\n";
		playerMoney -= 280;
		computerMoney += 280;
	}
	else if (Marvingardens != 'u')
	{
		cout << "Would you like to colonize Marvin Gardens? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 280)
		{
			Marvingardens = 'u';
			playerMoney -=280;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Marvin Gardens.\n";
}
void pacificAvenue()
{
	if(Pacificavenue == 'c')
	{
		cout << "You have to pay $300 to the computer\n";
		playerMoney -= 300;
		computerMoney += 300;
	}
	else if (Pacificavenue != 'u')
	{
		cout << "Would you like to colonize Pacific Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 300)
		{
			Pacificavenue = 'u';
			playerMoney -=300;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Pacific Avenue.\n";
}
void ncAvenue()
{
	if(NCavenue == 'c')
	{
		cout << "You have to pay $300 to the computer\n";
		playerMoney -= 300;
		computerMoney += 300;
	}
	else if (NCavenue != 'u')
	{
		cout << "Would you like to colonize North Carolina Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 300)
		{
			NCavenue = 'u';
			playerMoney -=300;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own North Carolina Avenue.\n";
}
void pennAvenue()
{
	if(Pennavenue == 'c')
	{
		cout << "You have to pay $320 to the computer\n";
		playerMoney -= 320;
		computerMoney += 320;
	}
	else if (Pennavenue != 'u')
	{
		cout << "Would you like to colonize Pennsylvania Avenue? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 300)
		{
			Pennavenue = 'u';
			playerMoney -=320;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Pennsylvania Avenue.\n";
}
void shortLine()
{
	if(Shortline == 'c')
	{
		cout << "You have to pay $100 to the computer\n";
		playerMoney -= 100;
		computerMoney += 100;
	}
	else if (Shortline != 'u')
	{
		cout << "Would you like to colonize Short Line? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 200)
		{
			Shortline = 'u';
			playerMoney -=200;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Short Line.\n";
}
void parkPlace()
{
	if(Parkplace == 'c')
	{
		cout << "You have to pay $350 to the computer\n";
		playerMoney -= 350;
		computerMoney += 350;
	}
	else if (Parkplace != 'u')
	{
		cout << "Would you like to colonize Park Place? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 350)
		{
			Parkplace = 'u';
			playerMoney -=350;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Park Place.\n";
}
void luxuryTax()
{

}
void broadway()
{
	if(Broadway == 'c')
	{
		cout << "You have to pay $400 to the computer\n";
		playerMoney -= 400;
		computerMoney += 400;
	}
	else if (NCavenue != 'u')
	{
		cout << "Would you like to colonize Broadway? (y/n): ";
		cin >> yn2;
		if(yn2 != 'n' && playerMoney >= 400)
		{
			Broadway = 'u';
			playerMoney -=400;
		}
		else if (yn2 != 'n')
			cout << "Sorry! You don't have enough money!\n";
	}
	else
		cout << "You already own Broadway.\n";
}