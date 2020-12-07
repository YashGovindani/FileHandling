#include<stdio.h>
#include<string.h>
void addFriend()
{
char name[22],contactNumber[52];
FILE *f;
printf("Enter name : ");
fgets(name,22,stdin);
fflush(stdin);
fpurge(stdin); // for mac OS
name[strlen(name)-1]='\0';
printf("Enter contact number : ");
fgets(contactNumber,52,stdin);
fflush(stdin);
fpurge(stdin); // for mac OS
contactNumber[strlen(contactNumber)-1]='\0';
f=fopen("friends.ddd","a");
fputs(name,f);
fputc('\n',f);
fputs(contactNumber,f);
fputc('\n',f);
fclose(f);
printf("Friend added\n");
}
void displayListOfFriends()
{
FILE *k;
char name[22],contactNumber[52];
k=fopen("friends.ddd","r");
if(k==NULL)
{
printf("No friend added\n");
return;
}
while(1)
{
fgets(name,22,k);
if(feof(k)) break;
name[strlen(name)-1]='\0';
fgets(contactNumber,52,k);
contactNumber[strlen(contactNumber)-1]='\0';
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
printf("2. Display lost of friends\n");
printf("3. Exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
fflush(stdin);
fpurge(stdin); // for mac OS
if(choice==1) addFriend();
if(choice==2) displayListOfFriends();
if(choice==3) break;
}
return 0;
}
