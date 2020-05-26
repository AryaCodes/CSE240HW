
#include <stdio.h>
void main()
{
char ch;
ch = '+';
int f, a = 10, b = 20;
printf("ch = %c\n", ch);
switch (ch) {
case '+': f = a + b; printf("f = %d\n", f); break;
case '-': f = a - b; printf("f = %d\n", f); break;
case '*': f = a * b; printf("f = %d\n", f); break;
case '/': f = a / b; printf("f = %d\n", f); break;
default: printf("invalid operator\n");
}
ch = '-';
a = 10, b = 20;
printf("ch = %c\n", ch);
switch (ch) {
case '+': f = a + b; printf("f = %d\n", f); break;
case '-': f = a - b; printf("f = %d\n", f); break;
case '*': f = a * b; printf("f = %d\n", f); break;
case '/': f = a / b; printf("f = %d\n", f); break;
default: printf("invalid operator\n");
}
ch = '*';
a = 10, b = 20;
printf("ch = %c\n", ch);
switch (ch) {
case '+': f = a + b; printf("f = %d\n", f); break;
case '-': f = a - b; printf("f = %d\n", f); break;
case '*': f = a * b; printf("f = %d\n", f); break;
case '/': f = a / b; printf("f = %d\n", f); break;
default: printf("invalid operator\n");
}
ch = '/';
a = 10, b = 20;
printf("ch = %c\n", ch);
switch (ch) {
case '+': f = a + b; printf("f = %d\n", f); break;
case '-': f = a - b; printf("f = %d\n", f); break;
case '*': f = a * b; printf("f = %d\n", f); break;
case '/': f = a / b; printf("f = %d\n", f); break;
default: printf("invalid operator\n");
}
ch = '%';
a = 10, b = 20;
printf("ch = %c\n", ch);
switch (ch) {
case '+': f = a + b; printf("f = %d\n", f); break;
case '-': f = a - b; printf("f = %d\n", f); break;
case '*': f = a * b; printf("f = %d\n", f); break;
case '/': f = a / b; printf("f = %d\n", f); break;
default: printf("invalid operator\n");
}
}