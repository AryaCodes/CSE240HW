
/*	CSE 40 Assignment 1: Math Loop
	Name: Arya Manish Tawde
	Description: This program loops through user-inputted airthmatic operaters
		     and performs them on pre-set integers, computes and displays the answer.
*/
	

#include <stdio.h>
int main()
{
//Declaring and assigning variables;
char ch;
int f, a= 10, b=20;
float g;


while(1)
{

//Scanning the input and clearing the buffer afterwards.
scanf("%c", &ch);
while((getchar())!= '\n');

//Operating the switch appropriately
switch (ch) 
{case '+': f = a + b; printf("f = %d\n", f); break;
case '-': f = a - b; printf("f = %d\n", f); break; 
case '*': f = a * b; printf("f = %d\n", f); break; 
case '/': g = ((double)a / b); printf("f = %.2f\n", g); break;
default: printf("invalid operator\n");  } 

if(ch == 'q')
break;
}


}