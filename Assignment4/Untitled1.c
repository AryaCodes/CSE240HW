#include<iostream>

using namespace std;


int fun2(int* a, int b)
{
a = &b;
*a = 10;
int c = *a + b;
return c;
}

int main()
{
int a = 1;
int b = 2;
cout << fun2(&a, b);
cout << a << " " << b;
}
