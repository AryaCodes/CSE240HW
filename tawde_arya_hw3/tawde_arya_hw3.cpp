/*
Title: CSE240 Assignment 3
Author: Arya Manish Tawde
Date: 29th June 2020
Description: This program procedurally generates maps based on required specifications.
             It prints out the map in the terminal with color.
*/

//Declaring the libraries. Also using termcolor for colour output.

#include<cstdlib>
#include<ctime>
#include<iostream>
#include"termcolor.hpp"


using namespace std;  //Since we will be using the namespace a lot.


//Function Initial Declarations
int isIntInValid(int, int, int);
void normalMode();
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
 Function Description: main() is the primary function. Here it serves as the basic menu for the application. User can
                       generate map or exit.
 Input Parameters: Not Applicable.
 Returns: 0 if program runs smoothly.
*/
int main(int argc, char* argv[])
{
    int choice = 1;

    cout<< "Welcome to Fantasy Land Generator" << endl;

    srand((unsigned)time(0));                           // SEEDING the Rand with time for true pseudo randomness.

    while(true)                                         //The loop necessitates valid choices only, 1 operates application 0 exits
    {
        cout<<endl<< "Make a choice!"<< endl;
        cout<< "1. Generate a map!"<< endl;
        cout<< "0. Exit"<< endl;

        cin>> choice;


        if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<< "Enter an integer choice only!"<< endl;
            continue;
        }

        if(!isIntInValid(choice, 0, 1))
        {
            cin.ignore(100,'\n');
            cout<< "Enter a valid choice please"<< endl;
            continue;
        }

        cin.ignore(100,'\n');

        if(choice)
            normalMode();

        if(!choice)
            break;
    }

}

/*
 Function Description: normalMode() serves to accept a valid height and width from the user. It will mandate correct values.
                       It also calls the printing function.
 Input Parameters: Not Applicable.
 Returns: Void
*/
void normalMode()
{
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

/*
 Function Description: The generation of the map happens primarily in this function.
                       It calls other functions to generate chars for the array, but the primary algorithm is here.
 Input Parameters: Accepts width and height as integers.
 Returns: Char** pointer to the 2-D Array containing the region map generated.
*/

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

/*
 Function Description: Generates a completely random Land Type!
 Input Parameters: Not Applicable.
 Returns: One of 6 different Land Types as distinct characters.
*/
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
    return 'o';
}

/*
 Function Description: generateNeighbour() calls newFromX type functions that follow depending on the input char type.
                        The newFromX then generate chars based on probability in specifications.
 Input Parameters: Char of source place.
 Returns: Returns the generated neighboring land as a char.
*/

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
    else
        return 'o';

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
    else
        return 'o';
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
    else
        return 'o';
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
    else
        return 'o';
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
    else
        return 'o';
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
    else
        return 'o';
}

/*
 Function Description: This prints the land in the char array. It also serves to add color effects.
 Input Parameters: char** pointer containing the region map.
 Returns: Void
*/
void printLand(char** land, int width, int height)
{
    for(int temp = 0; temp<height; temp++)
        {
            for(int temp2 = 0; temp2<width; temp2++)
            {
                switch(land[temp][temp2])
                {
                case 'R':
                    cout<< termcolor::on_green<< termcolor::white << land[temp][temp2];
                    break;
                case 'F':
                    cout<< termcolor::on_green<< termcolor::grey << land[temp][temp2];
                    break;
                case 'T':
                    cout<< termcolor::on_yellow<< termcolor::grey << land[temp][temp2];
                    break;
                case 'C':
                    cout<< termcolor::on_magenta<< termcolor::yellow << land[temp][temp2];
                    break;
                case 'M':
                    cout<< termcolor::reset << land[temp][temp2];
                    break;
                case 'W':
                    cout<< termcolor::on_blue<< termcolor::white << land[temp][temp2];
                    break;
                }
            }
            cout<< termcolor::reset<<endl;
        }
}
/*
 Function Description: Checks that input int is in required range.
 Input Parameters: input from user, and allowed range as max and min.
 Returns: 1 if Valid, 0 if Invalid.
*/
int isIntInValid(int input, int minVal, int maxVal)
{
    if(input>= minVal &&input<=maxVal)
        return 1;
    else
        return 0;
}
/*
 Function Description: Generates Random integer in Range.
 Input Parameters: Range in form of Max and Min int.
 Returns: The Random integer.
*/
int randomInRange(int min, int max)
	{
	return (min + (rand()%(max + 1 -min)));
	}
