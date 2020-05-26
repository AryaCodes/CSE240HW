
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

//Showing the user the initial variables
printf("a = 20 ; b = 20\n");

while(1)
{
//Asking for input
printf("Enter the command you want to do!\n+ adds\n- subtracts\n* multiplies\n/ divides\n%% gives remainder\nq quits\n");

//Scanning the input and clearing the buffer afterwards.
scanf("%c", &ch);
while((getchar())!= '\n');

//Operating the switch appropriately
switch (ch) 
{case '+': f = a + b; printf("a + b = %d\n", f); break;
case '-': f = a - b; printf("a - b = %d\n", f); break; 
case '*': f = a * b; printf("a * b = %d\n", f); break; 
case '/': g = ((double)a / b); printf("a / b = %f\n", g); break;
case '%': f =  a%b;  printf("a %% b = %d\n", f); break;
case 'q': break;
default: printf("invalid operator\n");  } 

if(ch == 'q')
break;
}


}