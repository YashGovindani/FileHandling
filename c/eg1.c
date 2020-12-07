#include<stdio.h>
#include<string.h>
void addFriend()
{
char name[22],contactNumber[52];
FILE *f;
int x;
printf("Enter name : ");
fgets(name,22,stdin);
fpurge(stdin); // for mac OS
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter contact number : ");
fgets(contactNumber,52,stdin);
fpurge(stdin); // for mac OS
fflush(stdin);
contactNumber[strlen(contactNumber)-1]='\0';
f=fopen("friends.ddd","a");
for(x=0;name[x]!='\0';x++) fputc(name[x],f);
fputc('\n',f);
for(x=0;contactNumber[x]!='\0';x++) fputc(contactNumber[x],f);
fputc('\n',f);
fclose(f);
printf("Friend added\n");
}
void displayListOfFriends()
{
FILE *k;
int x;
char g;
char name[21],contactNumber[51];
k=fopen("friends.ddd","r");
if(k==NULL)
{
printf("No friends added\n");
return;
}
while(1)
{
g=fgetc(k);
if(feof(k)) break;
name[0]=g;
x=1;
while(1)
{
g=fgetc(k);
if(g=='\n') break;
name[x]=g;
x++;
}
name[x]='\0';
x=0;
while(1)
{
g=fgetc(k);
if(g=='\n') break;
contactNumber[x]=g;
x++;
}
contactNumber[x]='\0';
printf("Name : %s, Contact Number : %s\n",name,contactNumber);
}
fclose(k);
}
int main()
{
int choice;
while(1)
{
printf("1. Add friend\n");
printf("2. Display list of friends\n");
printf("3. Exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
fpurge(stdin); // for mac OS
fflush(stdin);
if(choice==1) addFriend();
if(choice==2) displayListOfFriends();
if(choice==3) break;
}
return 0;
}
