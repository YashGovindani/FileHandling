#include<stdio.h>
int main()
{
char a[21];
printf("Enter your name : ");
scanf("%[^\n]",a);
fflush(stdin);
fpurge(stdin); // for mac OS
printf("%s\n",a);
return 0;
}
