#include<stdio.h>
#include<string.h>
int main()
{
int rollNumber;
char name[21];
int std;
char sec;
FILE *f;
rollNumber=101;
strcpy(name,"Suresh Sharma");
std=1;
sec='A';
f=fopen("whatever.xyz","w");
fprintf(f,"%d %s\n%d %c",rollNumber,name,std,sec);
rollNumber=102;
strcpy(name,"Ramesh Joshi");
std=3;
sec='B';
fprintf(f,"%d %s\n%d %c",rollNumber,name,std,sec);
fclose(f);
return 0;
}
