#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>

using namespace std;

int menu();
void miniGames();
void macrosVFunction();
int randomInRange( int, int);
int isInt(char a[]);
int charToInt(char b);
int strToInt(char a[], int length);
int powerCal(int base, int power);

int main(int argc, char* argv[])
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
	{
	char arr1[20];
	cin >> arr1;
	cin.ignore(100, '\n');
	int x = isInt(arr1);
	if(x==0)
		cout<< "Please enter an integer" << endl;
	else
		cout << strToInt(arr1, x) +1 << endl;
	}





void macrosVFunction()
{cout<<"In Macros rolling d6:" << endl;}

int randomInRange(int min, int max)
	{
	return (min + (rand()%(max + 1 -min)));
	}

int isInt(char a[])
	{
	int x = 0;
	while(a[x]!='\0')
		{
		if( (a[x]<48) || (a[x]>57) )
			return 0;	
		x++;
		cout<< "In isInt"<< endl; 
		}
	return x;	
	}

int strToInt(char a[], int length)
	{
	int x = 0;
	int value = 0;
	while(x <= length)
		{
		value += charToInt(a[x]) * powerCal(10, length -x);
		}		
	return value;
	}

int charToInt(char b)
	{
	switch(b)
		{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
		}

	}

int powerCal(int base, int power)
	{
	cout<< "In power"<< endl;
	if(power == 0)
		return 1;
	else
		return (base * powerCal(base, (power-1))); 
	}
