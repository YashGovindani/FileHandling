#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
void addFriend()
{
char name[22],contactNumber[82];
std::cout<<"Enter name :";
fgets(name,22,stdin);
fflush(stdin);
fpurge(stdin); // for mac OS
name[strlen(name)-1]='\0';
std::cout<<"Enter contact number : ";
fgets(contactNumber,82,stdin);
fflush(stdin);
fpurge(stdin); // for mac OS
contactNumber[strlen(contactNumber)-1]='\0';
std::ofstream f("friends.ddd",std::ios::app);
int i;
i=0;
while(name[i]!='\0')
{
f<<name[i];
i++;
}
f<<'!';
i=0;
while(contactNumber[i]!='\0')
{
f<<contactNumber[i];
i++;
}
f<<'!';
f.close();
std::cout<<"Friend added"<<std::endl;
}
void displayListOfFriends()
{
std::ifstream k("friends.ddd");
if(k.fail()) // returns true if last operation failed
{
std::cout<<"No friends added"<<std::endl;
return;
}
char name[21];
char contactNumber[81];
int x;
char m;
while(1)
{
k>>m;
if(k.fail()) break;
name[0]=m;
x=1;
while(1)
{
k>>m;
if(m=='!') break;
name[x]=m;
x++;
}
name[x]='\0';
x=0;
while(1)
{
k>>m;
if(m=='!') break;
contactNumber[x]=m;
x++;
}
contactNumber[x]='\0';
std::cout<<"Name : "<<name<<", Contact number : "<<contactNumber<<std::endl;
}
k.close();
}
int main()
{
int choice;
while(1)
{
std::cout<<"1. Add friend"<<std::endl;
std::cout<<"2. Display list of friends"<<std::endl;
std::cout<<"3. Exit"<<std::endl;
std::cout<<"Enter your choice : ";
std::cin>>choice;
fflush(stdin);
fpurge(stdin);
if(choice==1) addFriend();
if(choice==2) displayListOfFriends();
if(choice==3) break;
}
return 0;
}
