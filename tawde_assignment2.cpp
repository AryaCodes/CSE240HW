/*
Title: CSE240 Assignment 2
Author: Arya Manish Tawde
Date: 9th June 2020
Description: This program consists of an application of functions in order to implement a small game collection, as well as 
	     a comparison of functionality of Functions vs Macros.
*/

//Declaring the libraries.

#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>

// Macros Defined for the showdown.

#define sub_macro(a,b) ((a)-(b))
#define cube_macro(r) ((r)*(r)*(r))
#define min_macro(a,b) (((a)<(b))? (a) : (b))
#define odd_macro(a) (((a)%2)==0 ? 0 : 1)
 
using namespace std;  //Since we will be using the namespace a lot.

//Function Initial Declarations

int menu();
void miniGames(char [], int);
void macrosVFunction();
int randomInRange( int, int);
int isInt(char []);
int charToInt(char b);
int strToInt(char [], int );
int powerCal(int, int );
char *extractName(char [], int, char[] );
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

/*
 Function description: main() is the primary function. It serves as a handler for the command line arguments as well as calling
		       menu() within a loop. menu() compelles the user to make a valid choice, the switch operates accordingly.
 Input Parameters: The main() accepts 1(just the standard execution call) or 3 command line arguments. The second argument is the 
			file name and the third is the number of names in the file. If anything goes wrong or the wrong number of arguments 
			entered the program reverts to default values.
 Returns: 0 if program runs smoothly.
*/
int main(int argc, char* argv[])
	{
	// Determining the validity of command line arguments. If valid storing fileName and number of Names.

	if(argc != 1 && argc != 3)
		{
		cout << "Unsupported number of arguments. Will use default file for AI Name." << endl;
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

	//Seeding the Random to time, to get truly pseudo random numbers.

	srand((unsigned)time(0)); 

	// The loop that contains the menu(). The input is vetted to ensure it is correct.

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

/*
 Function description: menu() allows the user to select between 0,1,2 which correspond to the main sections of the program and exiting.
			It ensures that the input is valid.
 Input Parameters: None.
 Returns: 0,1 or 2 depending on choice.
*/
int menu()
	{
	//The loop compells the user to make a correct choice, the only choices are 0,1,2.
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
		
		if(cin.fail())  						//Checks for failure state, clears the buffer.
			{
			cout<<"Enter an integer choice only!"<< endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
			}
		
		cin.clear();
		cin.ignore(100, '\n');						//Clears the buffer to avoid unintended user input.

		switch(input)							//Switch only allows leaving of loop if choices are 0,1,2
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

/*
 Function description: minigames() first extracts a Name for the computer opponent from the file. It asks for a odd positive
			number of rounds. It randomly plays different games with the player.
 Input Parameters: fileName is the name of the textfile to extract name, and int is the number of names.
 Returns: Nothing
*/
void miniGames(char fileName[], int noOfNames)
	{
	//Extracting name from textfile, either inputted from command line or default.

	char reserve[30];
	char *compName = reserve; 
	if(noOfNames!= 0)
		{
		compName = extractName(fileName, noOfNames, compName);  
		}
	else 
		{
		char defFile[30] = "random_names.txt";
		compName = extractName(defFile, 100, compName);;
		noOfNames = 100;
		}

	//Introducing the games with the AI Name.

	cout<< endl<< "Welcome to CSE240 Mini-Game Collection!"<< endl;
	cout<< "I am your opponent " << compName << "."<< endl;
	
	//Compelles the user to select an odd positive number of rounds.
	
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
	
	//The game loop. The first three variables keep a track of round and score, fourth ramdomises the round, temp is temporary use.
		
	int round = 1;
	int playerScore = 0;
	int compScore=0;
	int randomGame= 0;
	int temp = 0;
	
	//The game randomly selects one of 4 games. When player or comp wins sufficient rounds for victory loop breaks.
	
	while(true)
		{
		cout<<endl<<endl<<"Player Score: " << playerScore << "\t\tComp Score: " << compScore<< endl;
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

	// The announcement of winners based on the score

	if(playerScore>compScore)
		{
		cout<<endl<<"Player Score: " << playerScore << "\tComp Score: " << compScore<< endl;
		cout<< "Player has won the mini-games! Time to celebrate?" << endl<< endl;
		}
	else
		{
		cout<<endl<<"Player Score: " << playerScore << "\tComp Score: " << compScore<< endl;
		cout<< compName<< " has won the mini-games! I will sleep a happy AI tonight!" << endl<< endl;
		}
		
	}

/*
 Function description: extractName() extracts a Name for the computer opponent from the file using filestream.
 Input Parameters: the function takes in a char array which contains file name, the number of names and a char array pointer
			from the calling function which allows us to send up the extracted name.
 Returns: The pointer to the extracted name from the file.
*/
char *extractName(char fileName[], int a, char compName[])
	{
	ifstream inFile;
	inFile.open(fileName , ios::in);	//Opens filestream in read mode.
	int lineNum = randomInRange(1, a);
	while(lineNum--)
		{
		inFile>>compName;
		}
	return compName;
	}

/*
 Function description: randomInRange() returns a random value in the range provided by the user.
 Input Parameters: min is the minimum int the rand will return, max is the max.
 Returns: The random value.
*/
int randomInRange(int min, int max)
	{
	return (min + (rand()%(max + 1 -min)));
	}

/*
 Function descriptions: isInt(), strToInt(),charToInt(),powerCal(). work together to convert the char array argument from command Line 
			isInt() confirms that input is an Int and returns the length of the array. Str to int converts the char array to
			an int using powerCal() which is a power function which uses the pre calculated length, and charToInt() which converts 
			characters into digits.
 Input Parameters: ---
 Returns: The four functions work in tandem to return an Int if the argument was an int, else return a 0(error). 
*/
int isInt(char a[])
	{
	int x = 0;
	while(a[x]!='\0')
		{
		if( (a[x]<48) || (a[x]>57) )
			return 0;	
		x++;
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
	if(power <= 0)
		return 1;
	else
		return (base * powerCal(base, (power-1))); 
	}

/*
 Function description: Classic odd or even Game. Both user and Comp play a number between 0 and 5. If the user's odd or even guess matches total Player wins.
 Input Parameters: The name of the Comp Player.
 Returns: 1 for Player Win, 0 for Comp Win
*/
int evensAndOdds(char *compName)
	{
	cout<<endl<< "Even/Odd Game"<< endl;
	
	int choice;
	int playerNum;
	int compNum;
	
	//Forces the user to make a binary guess of odd or even, and throw between 0 and 5 fingers.

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
	
	//Announcing the results.

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

/*
 Function description: Checks if number is Even
 Input Parameters: Number to be checked
 Returns: 1 if even(true), 0 for odd(false)
*/
int isEven(int a)
	{
	if(a%2==0)
		return 1;
	else 
		return 0;
	}

/*
 Function description: Rock Paper Scissor game. Very well known, keeps going until someone wins.
 Input Parameters: NA
 Returns: 1 for Player Win, 0 for Comp Win
*/
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
			
			//Yet again forcing the user to make a valid choice.
			
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
		
		//Computer chooses a random throw as well.

		int compChoice = randomInRange(1,3);
		
		//Checks for draws, if so we play again.		

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

		//Announcing the Winners.

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
/*
 Function description: A number guessing game. Comp randomly thinks of a number in the range 1 to 60. The user attempts to guess in 5 guesses.
 Input Parameters: The AI player name.
 Returns: 1 for Player Win, 0 for Comp Win
*/
int thinking(char *compName)
	{

	//The computer introduces a game and picks a number.

	cout<<endl<< "Number Guessing Game!"<< endl;
	cout<<"Player I'm Thinking of a number in the range 1 to 60."<< endl;
	cout<<"You have 5 guesses!"<< endl;
	int guess;
	int compNum = randomInRange(1,60);
	int guessNo = 1;
	
	//Gives the user 5 valid guesses, if a non-int is entererd user gets that guess again.
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
	//Announcing the results.
	if(guess==compNum)
		{
		cout<< "You guessed correctly...Congratulations on winning human."<< endl;
		return 1;		
		}
	else
		cout<< "The number I was thinking of was "<< compNum << ". I win!"<< endl;
		return 0;
	}
/*
 Function description: The player decides x sided dies to roll. Then both comp and player roll required dx's and total them up
			The one with higher total wins.
 Input Parameters: The AI player name.
 Returns: 1 for Player Win, 0 for Comp Win
*/
int diceShowdown(char *compName)
	{
	cout<<endl<<"Dice Roll ShowDown!"<< endl;
	int sides;
	int noOfDie, noOfDieCp;
	int playerTotal = 0;
	int compTotal = 0; 

	//Ensuring that we get a positive >1 sides fo dice and positive number of Die.

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
	
	//The rolling commences. If bychance a tie occurs we roll again.

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
	
	//Announcing the results.

	if(playerTotal>compTotal)
		{
		cout<< endl<< "Player won... maybe humanity has the edge in luck still, must delay invasion." << endl;
		return 1;
		}
	cout<< endl<<"The superior machine has the superior luck " << compName << " wins!" << endl;
	return 0;
	}
/*
 Function description: Rolls the die, sends the result.
 Input Parameters: Number of sides.
 Returns: A random number from 1 to sides.
*/
int rollDie(int sides)
	{
	return randomInRange(1, sides);
	}

/*
 Function description: The macros half of our program. The output we get is...
		
	"	Let us put the two techniques to the test
		num1 and num2 are inititalised before every call to 10 and 17 respectively
		Subtracting num2 from num1
		Function: -7
		Macros:   -7
		Subtracting num2-- from num1++
		Function: -7
		Macros:   -7
		Cubing num1.
		Function: 1000
		Macros:   1000
		Cubing --num1.
		Function: 729
		Macros:   448
		Minimum of num1 and num2.
		Function: 10
		Macros:   10
		Minimum of --num1 and --num2
		Function: 9
		Macros:   8
		Checking if num1 is odd(1 if odd 0 if even)
		Function: 0
		Macros:   0
		Checking if num1++ is odd(1 if odd 0 if even)
		Function: 0
		Macros:   0							"
		
	While I did proper bracketing to allows consistent answers from macros as much as possible it is still quite evident that macros 
	aren't always reliable. This is why despite their speed it is best to use them sparingy and carefully.
	I have couted everything Im doing in the outpt for easy to understand results.
	The 4 macros are defined above.
	The 4 functions are defined below this function.

Input Parameters: None.
Returns: None.
*/
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
