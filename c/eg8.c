#include<stdio.h>
struct Employee
{
int id;
char name[21];
int salary;
};
void addEmployee()
{
struct Employee emp;
FILE *f;
printf("Enter employee Id. : ");
scanf("%d",&emp.id);
fflush(stdin);
fpurge(stdin); // for mac OS
printf("Enter name : ");
scanf("%[^\n]",emp.name);
fflush(stdin);
fpurge(stdin); // for mac OS
printf("Enter salary : ");
scanf("%d",&emp.salary);
fflush(stdin);
fpurge(stdin); // for mac OS
f=fopen("emp.dat","ab");
fwrite(&emp,sizeof(struct Employee),1,f);
fclose(f);
printf("Employee added\n");
}
void displayListOfEmployees()
{
struct Employee emp;
FILE *f;
f=fopen("emp.dat","rb");
if(f==NULL)
{
printf("No employees added\n");
return;
}
while(1)
{
fread(&emp,sizeof(struct Employee),1,f);
if(feof(f)) break;
printf("Id. : %d, Name : %s, Salary : %d\n",emp.id,emp.name,emp.salary);
}
fclose(f);
}
int main()
{
int choice;
while(1)
{
printf("1. Add employee\n");
printf("2. Display list of employees\n");
printf("3. Exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
fflush(stdin);
fpurge(stdin); // for mac OS
if(choice==1) addEmployee();
if(choice==2) displayListOfEmployees();
if(choice==3) break;
}
return 0;
}
