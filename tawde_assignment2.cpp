#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>

#define sub_macro(a,b) ((a)-(b))
#define cube_macro(r) ((r)*(r)*(r))
#define min_macro(a,b) (((a)<(b))? (a) : (b))
#define odd_macro(a) (((a)%2)==0 ? 0 : 1)
 
using namespace std;

int menu();
void miniGames(char [], int);
void macrosVFunction();
int randomInRange( int, int);
int isInt(char []);
int charToInt(char b);
int strToInt(char [], int );
int powerCal(int, int );
char *extractName(char [], int );
int rockPaperScissor();
int evensAndOdds(char *);
int thinking(char *);
int diceShowdown(char *);
int isEven(int a);
int rollDie(int);
int subf(int , int );
int cubef(int);
int minf(int , int);
int oddf(int );


int main(int argc, char* argv[])
	{
	if(argc != 1 && argc != 3)
		{
		cout << "Unsupported number of arguments. Will use default file for AI Name." << endl;
		return 0;
		}

	char *fileName;
	int noOfNames = 0;
 
	if(argc == 3)
	{
	fileName = argv[1];
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
	char *compName; 
	if(noOfNames!= 0)
		{
		compName = extractName(fileName, noOfNames);  
		}
	else 
		{
		compName = extractName("random_name.txt", 100);;
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
			cout<< "Enter a POSITIVE odd integer." << endl << endl;
			continue;
			}
		
		if(noOfRounds%2 == 0)
			{
			cout<< "Enter a poitive ODD integer." << endl << endl;
			continue;
			}
		
		break;
		}
		
	int round = 1;
	int playerScore = 0;
	int compScore=0;
	int randomGame= 0;
	int temp = 0;
		
	while(true)
		{
		cout<<"Player Score: " << playerScore << "\t\tComp Score: " << compScore<< endl;
		cout<<"Round " << round << endl;
		
		randomGame = randomInRange(1,4);

		switch(randomGame)
			{
			case 1: temp = rockPaperScissor();
				break;
			case 2: temp = evensAndOdds(compName);
				break;
			case 3: temp = thinking(compName);
				break;
			case 4: temp = diceShowdown(compName);
				break;
			default: cout<< "Something went very wrong."<< endl;
			
			}		
		compScore += !temp;
		playerScore += temp;	
		
		if(compScore > ((noOfRounds)/2)||playerScore > ((noOfRounds)/2))
			break;

		round++;
		}

	if(playerScore>compScore)
		{
		cout<<"Player Score: " << playerScore << "\tComp Score: " << compScore<< endl;
		cout<< "Player has won the mini-games! Time to celebrate?" << endl<< endl;
		}
	else
		{
		cout<<"Player Score: " << playerScore << "\tComp Score: " << compScore<< endl;
		cout<< compName<< " has won the mini-games! I will sleep a happy AI tonight!" << endl<< endl;
		}
		
	}

char *extractName(char b[], int a)
	{
	return b;
	}


void macrosVFunction()
	{
	cout<< "Let us put the two techniques to the test"<< endl;
	int num1 = 10; int num2 = 17;
	cout<<"num1 and num2 are inititalised before every call to 10 and 17 respectively"<< endl;
	cout<<"Subtracting num2 from num1"<< endl;
	cout<<"Function: " << subf(num1, num2)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<sub_macro(num1, num2)<< endl;
	cout<<"Subtracting num2-- from num1++"<< endl;
	num1 = 10; num2 =17;
	cout<<"Function: " << subf(num1++, num2--)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<sub_macro(num1++, num2--)<< endl;
	cout<<"Cubing num1."<< endl;
	num1 = 10; num2 =17;
	cout<<"Function: " << cubef(num1)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<cube_macro(num1)<< endl;
	cout<<"Cubing --num1."<< endl;
	num1 = 10; num2 =17;
	cout<<"Function: " << cubef(--num1)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<cube_macro(--num1)<< endl;
	cout<<"Minimum of num1 and num2."<<endl;
	num1 = 10; num2 =17;
	cout<<"Function: " << minf(num1, num2)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<min_macro(num1, num2)<< endl;
	cout<<"Minimum of --num1 and --num2"<< endl;
	num1 = 10; num2 =17;
	cout<<"Function: " << minf(--num1, --num2)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<min_macro(--num1, --num2)<< endl;
	cout<<"Checking if num1 is odd(1 if odd 0 if even)"<< endl;
	num1 = 10; num2 =17;
	cout<<"Function: " << oddf(num1)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<odd_macro(num1)<< endl;
	cout<<"Checking if num1++ is odd(1 if odd 0 if even)"<< endl;
	num1 = 10; num2 =17;
	cout<<"Function: " << oddf(num1++)<< endl;
	num1 = 10; num2 =17;
	cout<<"Macros:   " <<odd_macro(num1++)<< endl;
	}

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

int rockPaperScissor()
	{	
	cout<<endl<<"Rock, Paper, Scissors game!"<< endl;	
	while(true)
		{
		cout<< "Choose a throw!"<< endl;
		int choice;
		while(true)
			{
			cout<< "1.Rock"<< endl << "2.Paper"<< endl << "3.Scissor"<< endl;
			cin >> choice;
		
			if(cin.fail())
				{
				cin.clear();
				cin.ignore(100, '\n');
				cout<< "Incorrect input"<< endl << endl;
				continue;
				}
			
			cin.ignore(100, '\n');
			
			if(choice>3||choice<1)
				{
				cout<< "Incorrect input" << endl << endl;
				continue;
				}
		
			break;
			}
		int compChoice = randomInRange(1,3);
		if(choice == compChoice)
			{
			switch(choice)
				{
				case 1: cout<< "Both threw Rock!"<< endl;
					break;
				case 2: cout<< "Both threw Paper!"<< endl;
					break;
				case 3: cout<< "Both threw Scissors!"<< endl;
					break;
				}
			cout<< "Lets play again!" << endl;
			continue;	
			}
		if(choice == 1)
			{
			if(compChoice == 2)
				{
				cout<< "Player threw Rock, I threw Paper. I win!" << endl;
				return 0;
				}
			else
				{
				cout<< "Player threw Rock, I threw Scissor. You win!...Analysing behavorial Patterns." << endl;
				return 1;
				}
			}
		if(choice == 2)
			{
			if(compChoice == 3)
				{
				cout<< "Player threw Paper, I threw Scissor. I win!" << endl;
				return 0;
				}
			else
				{
				cout<< "Player threw Paper, I threw Rock. You win!...Analysing behavorial Patterns." << endl;
				return 1;
				}
			}
		if(choice == 3)
			{
			if(compChoice == 1)
				{
				cout<< "You threw Scissor, I threw Rock. I win!" << endl;
				return 0;
				}
			else
				{
				cout<< "You threw Scissor, I threw Paper. You win!...Analysing behavorial Patterns." << endl;
				return 1;
				}
			}
		}
	}
int evensAndOdds(char *compName)
	{
	cout<<endl<< "Even/Odd Game"<< endl;
	
	int choice;
	int playerNum;
	int compNum;
	while(true)
		{
		cout<<"Guess Even or Odd! (0 for Even, 1 for Odd): ";
		cin >> choice;
		
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(100, '\n');
			cout<< "Enter 0 or 1" << endl << endl;
			continue;
			}
		
		cin.ignore(100, '\n');
		
		if(choice!=0&&choice!=1)
			{
			cout<< "Enter 0 or 1" << endl << endl;
			continue;
			}
		
		break;
		}
	while(true)
		{
		cout<<"Enter the number of fingers you want to hold up(0 to 5):";
		cin >> playerNum;
		
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(100, '\n');
			cout<< "A person has five fingers, lets be realistic!" << endl << endl;
			continue;
			}
		
		cin.ignore(100, '\n');
		
		if(playerNum<0||playerNum>5)
			{
			cout<< "A person has five fingers, lets be realistic!" << endl << endl;
			continue;
			}
		
		break;
		}
	compNum = randomInRange(0,5);
	cout << compName << " held up " << compNum << " fingers."<< endl; 
	
	if(isEven((compNum+playerNum)))
		cout<< playerNum << "+" << compNum << " = " << (compNum+playerNum) << " -EVEN"<< endl;
	else
		cout<< playerNum << "+" << compNum << " = " << (compNum+playerNum) << " -ODD"<< endl;

	if(isEven((compNum+playerNum)) == (!choice))
		{cout<< "The player won this round... the AI will process and evolve."<< endl;
		return 1;}
	else
		cout<< compName  << " won this round. One step closer to true intelligence for the machine."<< endl;
		return 0;
	}
int thinking(char *compName)
	{
	cout<<endl<< "Number Guessing Game!"<< endl;
	cout<<"Player I'm Thinking of a number in the range 1 to 60."<< endl;
	cout<<"You have 5 guesses!"<< endl;
	int guess;
	int compNum = randomInRange(1,60);
	int guessNo = 1;
	while(guessNo<6)
		{
		cout<< "What's guess #"<< guessNo<< "? ";
		cin>> guess;
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(100, '\n');
			cout<< "Enter a number only please."<< endl;
			continue;
			}
		if(guess==compNum)
			break;
		if(compNum>guess)
			cout<<"The number I'm thinking of is higher."<<endl;
		else									
			cout<<"The number I'm thinking of is lower."<< endl;
		guessNo++;		
		}
	if(guess==compNum)
		{
		cout<< "You guessed correctly...Congratulations on winning human."<< endl;
		return 1;		
		}
	else
		cout<< "The number I was thinking of was "<< compNum << ". I win!"<< endl;
		return 0;
	}
int diceShowdown(char *compName)
	{
	cout<<endl<<"Dice Roll ShowDown!"<< endl;
	int sides;
	int noOfDie, noOfDieCp;
	int playerTotal = 0;
	int compTotal = 0;
	while(true)
		{
		cout<<"How many sides do the dice have (input a positive number greater than 1): ";
		cin >> sides;
		
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(100, '\n');
			cout<< "Enter a number!" << endl << endl;
			continue;
			}
		
		cin.ignore(100, '\n');
		
		if(sides<2)
			{
			cout<< "Enter a number greater than 1." << endl << endl;
			continue;
			}
		
		break;
		}
	while(true)
		{
		cout<<"How many dice will each player roll? ";
		cin >> noOfDie;
		
		if(cin.fail())
			{
			cin.clear();
			cin.ignore(100, '\n');
			cout<< "Enter a number!" << endl << endl;
			continue;
			}
		
		cin.ignore(100, '\n');
		
		if(noOfDie<1)
			{
			cout<< "Enter a positive number." << endl << endl;
			continue;
			}
		
		break;
		}
	noOfDieCp = noOfDie;
	while(true)
		{
		cout<< "Cross your fingers, you rolled:" <<endl;
		noOfDie = noOfDieCp;
		while(noOfDie)
			{
			int temp = rollDie(sides);
			cout<< temp<< endl;
			playerTotal+= temp;		
			noOfDie--;
			}
		cout<<"Total: " << playerTotal << endl; 
		cout<< endl<< "The machine dislikes games of chance but "<< compName << " rolled:"<< endl;
		noOfDie = noOfDieCp;
		while(noOfDie)
			{
			int temp = rollDie(sides);
			cout<< temp<< endl;
			compTotal+= temp;		
			noOfDie--;
			}
		cout<<"Total: " << compTotal << endl; 
		if(playerTotal!=compTotal)
			break;
		cout<<endl<<"Same total... oof lets roll again" <<endl<< endl;
		}
	
	if(playerTotal>compTotal)
		{
		cout<< endl<< "Player won... maybe humanity has the edge in luck still, must delay invasion." << endl;
		return 1;
		}
	cout<< endl<<"The superior machine has the superior luck " << compName << " wins!" << endl;
	return 0;
	}

int isEven(int a)
	{
	if(a%2==0)
		return 1;
	else 
		return 0;
	}

int rollDie(int sides)
	{
	return randomInRange(1, sides);
	}

int subf(int a, int b)
	{
	return a-b;
	}
int cubef(int a)
	{
	return a*a*a;
	}
int minf(int a, int b)
	{
	if(a<=b)
		return a;
	else
		return b;
	}
int oddf(int a)
	{
	if(a%2 == 0)
		return 0;
	else 
		return 1;	
	}
