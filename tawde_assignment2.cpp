#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>

using namespace std;

int menu();
void miniGames(char [], int);
void macrosVFunction();
int randomInRange( int, int);
int isInt(char []);
int charToInt(char b);
int strToInt(char [], int );
int powerCal(int, int );
char *extractname(char b[], int a);

int main(int argc, char* argv[])
	{
	if(argc != 1 && argc != 3)
		{
		cout << "Unsupported number of arguments." << endl;
		return 0;
		}

	char fileName[];
	int noOfNames = 0;
 
	if(argc == 3)
	{
	fileName[] = argv[1];
	int x = isInt(argv[2]);
	if(x==0)
		cout<< "For number of names please enter a postive integer." << endl;
	else
		noOfNames = strToInt(argv[2], x);
		
	}


	srand((unsigned)time(0)); 
	while(1)
		{
		int choice = menu();
		switch(choice)
			{
			case 0: break;
			case 1: miniGames(fileName, noOfNames);
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

void miniGames(char fileName[], int noOfNames)
	{
	char compName[30]; 
	if(noOfNames!= 0)
		{
		compName[] = extractName(fileName, noOfNames);  
		}
	else 
		{
		compName[] = extractName("default.txt", 100);;
		noOfNames = 100;
		}

	cout<< "Welcome to CSE240 Mini-Game Collection!"<< endl;
	cout<< "I am your opponent " << compName << "."<< endl;
	
	int noOfRounds = 0;
 	while(true)
		{
		cout<< "How many rounds should we play? (Choose an odd positive number)" << endl;
		cin >> noOfRounds;
		
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(100, '\n');
			cout<< "Enter a positive even INTEGER." << endl << endl;
			continue;
			}
		
		cin.ignore(100, '\n');
		
		if(noOfRounds<0)
			{
			cout<< "Enter a POSITIVE even integer." << endl << endl;
			continue;
			}

		if(noOfRounds%2 != 0)
			{
			cout<< "Enter a poitive EVEN integer." << endl << endl;
			continue;
			}
		}
		cout<<"Tournament"<< endl;
	}

char *extractname(char b[], int a)
	{
	return b;
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
	while(x < length)
		{
		value += charToInt(a[x]) * powerCal(10, length -(x+1));
		x++;
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
	if(power <= 0)
		return 1;
	else
		return (base * powerCal(base, (power-1))); 
	}
