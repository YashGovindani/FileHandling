#include<stdio.h>
#include<string.h>
int main()
{
int rollNumber;
char name[21];
int std;
char sec;
FILE *f;
f=fopen("whatever.xyz","r");
fscanf(f,"%d %[^\n] %d %c",&rollNumber,name,&std,&sec);
printf("%d,%s,%d,%c\n",rollNumber,name,std,sec);
printf("****************\n");
fscanf(f,"%d %[^\n] %d %c",&rollNumber,name,&std,&sec);
printf("%d,%s,%d,%c\n",rollNumber,name,std,sec);
fclose(f);
return 0;
}
