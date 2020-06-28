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


using namespace std;  //Since we will be using the namespace a lot.


#define RST "\x1B[0m"
#define BBLU(x) "\x1B[104m" << x << RST
#define BGRN(x) "\x1B[102m" << x << RST
#define DGRN(x) "\x1B[42m" << x << RST
#define BMAG(x) "\x1B[105m" << x << RST
#define BYEL(x) "\x1B[103m" << x << RST

//Function Initial Declarations
int isIntInValid(int, int, int);
void normalMode();
void specialMode();
char** generateLand(int, int);
char pickLandType();
char generateNeighbour(char);
char newFromRuralLand();
char newFromForest();
char newFromTown();
char newFromWater();
char newFromCity();
char newFromMountain();
void printLand(char** , int, int);
int randomInRange( int, int);


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
    int choice = 1;

    cout<< "Welcome to Fantasy Land Generator" << endl;

    while(true)
    {
        srand((unsigned)time(0));

        cout<<endl<< "Make a choice!"<< endl;
        cout<< "1. Standard Specifications(Output Map in Terminal, Limited Size)"<< endl;
        cout<< "2. Special Mode(Creates a file with the map to use when required!)"<< endl;
        cout<< "0. Exit"<< endl;

        cin>> choice;


        if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<< "Enter an integer choice only!"<< endl;
            continue;
        }

        if(!isIntInValid(choice, 0, 2))
        {
            cin.ignore(100,'\n');
            cout<< "Enter a valid choice please"<< endl;
            continue;
        }

        cin.ignore(100,'\n');

        switch(choice)
        {
        case 1:
            normalMode();
            break;
        case 2:
            specialMode();
            break;
        }

    if(!choice)
        break;
    }

}

void normalMode()
{
    cout<<"In Normal Mode"<< endl;
    int height = 0 , width = 0;

    cout<<"Enter width (integer between 20 and 50)"<< endl;

    while(true)
    {
        cin>> width;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<< "Enter an integer choice only!"<< endl;
            continue;
        }

        if(!isIntInValid(width, 20, 50))
        {
            cin.ignore(100,'\n');
            cout<< "Number between 20 and 50 only."<< endl;
            continue;
        }

        cin.ignore(100,'\n');
        break;
    }


    cout<<"Enter height (integer between 20 and 50)"<< endl;

    while(true)
    {
        cin>> height;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<< "Enter an integer choice only!"<< endl;
            continue;
        }

        if(!isIntInValid(height, 20, 50))
        {
            cin.ignore(100,'\n');
            cout<< "Number between 20 and 50 only."<< endl;
            continue;
        }

        cin.ignore(100,'\n');


        char** land = generateLand(width, height);

        printLand(land, width, height);

        for(int temp = 0; temp<height; temp++)
        {
            delete[] land[temp];
        }

        delete[] land;
    break;
    }



}

void specialMode()
{
    cout<<"In special Mode"<< endl;
}

char** generateLand(int width, int height)
{
    char** land;
    land = new char* [height];

    for(int temp = 0; temp< height; temp++)
    {
        land[temp] = new char[width];
    }

    land[0][0] = pickLandType();

    for(int temp = 1; temp< width; temp++)
    {
    land[0][temp] = generateNeighbour(land[0][temp-1]);
    }

    for(int temp = 1; temp< height; temp++)
    {
    land[temp][0] = generateNeighbour(land[temp-1][0]);
    }

    for(int temp = 1; temp<height; temp++)
    {
        for(int temp2 = 1; temp2<width; temp2++)
        {
            if(randomInRange(0,1))
            {
                land[temp][temp2] = generateNeighbour(land[temp-1][temp2]);
            }
            else
            {
                land[temp][temp2] = generateNeighbour(land[temp][temp2-1]);
            }
        }
    }
    return land;
}

char pickLandType()
{
    int temp = randomInRange(1,6);
    switch(temp)
    {
        case 1:
            return 'R';
        case 2:
            return 'F';
        case 3:
            return 'T';
        case 4:
            return 'W';
        case 5:
            return 'C';
        case 6:
            return 'M';
    }
}

char generateNeighbour(char source)
{
    switch(source)
    {
    case 'R':
        return newFromRuralLand();
    case 'F':
        return newFromForest();
    case 'T':
        return newFromTown();
    case 'C':
        return newFromCity();
    case 'M':
        return newFromMountain();
    case 'W':
        return newFromWater();
    }
    return 'o';
}

char newFromRuralLand()
{
    int temp = randomInRange(1,100);
    if(temp<=40)
        return 'R';
    else if(temp<=65)
        return 'F';
    else if(temp<=80)
        return 'T';
    else if(temp<=90)
        return 'W';
    else if(temp<=90)
        return 'C';
    else if(temp<=100)
        return 'M';

}

char newFromForest()
{
    int temp = randomInRange(1,100);
    if(temp<=20)
        return 'R';
    else if(temp<=60)
        return 'F';
    else if(temp<=65)
        return 'T';
    else if(temp<=85)
        return 'W';
    else if(temp<=85)
        return 'C';
    else if(temp<=100)
        return 'M';
}

char newFromCity()
{
    int temp = randomInRange(1,100);
    if(temp<=0)
        return 'R';
    else if(temp<=15)
        return 'F';
    else if(temp<=40)
        return 'T';
    else if(temp<=50)
        return 'W';
    else if(temp<=90)
        return 'C';
    else if(temp<=100)
        return 'M';
}

char newFromMountain()
{
    int temp = randomInRange(1,100);
    if(temp<=5)
        return 'R';
    else if(temp<=20)
        return 'F';
    else if(temp<=25)
        return 'T';
    else if(temp<=40)
        return 'W';
    else if(temp<=50)
        return 'C';
    else if(temp<=100)
        return 'M';
}

char newFromTown()
{
    int temp = randomInRange(1,100);
    if(temp<=20)
        return 'R';
    else if(temp<=25)
        return 'F';
    else if(temp<=65)
        return 'T';
    else if(temp<=75)
        return 'W';
    else if(temp<=95)
        return 'C';
    else if(temp<=100)
        return 'M';
}

char newFromWater()
{
    int temp = randomInRange(1,100);
    if(temp<=15)
        return 'R';
    else if(temp<=35)
        return 'F';
    else if(temp<=40)
        return 'T';
    else if(temp<=80)
        return 'W';
    else if(temp<=90)
        return 'C';
    else if(temp<=100)
        return 'M';
}

void printLand(char** land, int width, int height)
{
    for(int temp = 0; temp<height; temp++)
        {
            for(int temp2 = 0; temp2<width; temp2++)
            {
                switch(land[temp]([temp2])
                {
                case 'R':
                    cout<< BGRN(land[temp][temp2]);
                    break;
                case 'F':
                    cout<< DGRN(land[temp][temp2]);
                    break;
                case 'T':
                    cout<< BYEL(land[temp][temp2]);
                    break;
                case 'C':
                    cout<< BMAG(land[temp][temp2]);
                    break;
                case 'M':
                    cout<< land[temp][temp2];
                    break;
                case 'W':
                    cout<< BBLU(land[temp][temp2]);
                    break;
                }
            }
            cout<< endl;
        }
}

int isIntInValid(int input, int minVal, int maxVal)
{
    if(input>= minVal &&input<=maxVal)
        return 1;
    else
        return 0;
}

int randomInRange(int min, int max)
	{
	return (min + (rand()%(max + 1 -min)));
	}
