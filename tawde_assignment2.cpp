#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int menu();
void miniGames();
void macrosVFunction();
int randomInRange( int, int);

int main()
	{
	srand((unsigned)time(0));
	while(1)
		{
		int choice = menu();
		switch(choice)
			{
			case 0: break;
			case 1: miniGames();
				break;
			case 2: macrosVFunction();
				break;
			default: cout<< "Something went very wrong."<< endl;
			}
		if(choice == 0)
			break;
		}
	return 0;
	}

int menu()
	{
	
	int choice = 0;
	while(!choice)
		{
		cout<<"Welcome to CSE240 Assignment 2!"<< endl;
		cout<<"Menu"<< endl;
		cout<<"1 - CSE240 Mini-Game Collection"<< endl;
		cout<<"2 - Macros vs Functions Throw-down"<< endl;
		cout<<"0 - Exit"<< endl;
		cout<<"Choose an option: ";
		
		int input;
		cin >> input;
		
		if(cin.fail())
			{
			cout<<"Enter an integer choice only!"<< endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
			}
		
		cin.clear();
		cin.ignore(100, '\n');

		switch(input)
			{
			case 1: choice = 1;
				break;
			case 2: choice = 2;
				break;
			case 0: choice = 3;
				break;
			default: cout<< "Please enter a valid choice!"<< endl<< endl;
			}
		
		}
		if(choice==3)
			return 0;
		else
			return choice;
	}

void miniGames()
{cout<< "In MiniGames rolling d100:"<< randomInRange(1, 100)<< " " << randomInRange(1, 100)  << endl;}
void macrosVFunction()
{cout<<"In Macros rolling d6:" << randomInRange(1,6)<< endl;}

int randomInRange(int min, int max)
	{
	return (min + (rand()%(max + 1 -min)));
	}