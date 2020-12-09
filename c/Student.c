#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char STUDENT_DATA_FILE[20];
typedef struct __student
{
int rollNumber;
char name[32];
char gender;
}Student;
void printHorizontalLine(char,int);
void clearTerminal();
void clearStdin();
void pressEnterToContinue();
void deleteFile(char *);
void addStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void displayListOfStudents();
int main()
{
strcpy(STUDENT_DATA_FILE,"students.data");
int choice;
clearTerminal();
printf("Welcome to Student Management System\n");
pressEnterToContinue();
clearTerminal();
while(1)
{
printf("Student Management System\n\n");
printf("1. Add student\n");
printf("2. Edit student\n");
printf("3. Delete student\n");
printf("4. Search student\n");
printf("5. Display list of students\n");
printf("6. Exit\n");
printf("Enter your choice (1-6) : ");
scanf("%d",&choice);
clearStdin();
clearTerminal();
if(choice<1 || choice>6)
{
printf("Invalid choice : %d\n",choice);
pressEnterToContinue();
}
else if(choice==1) addStudent();
else if(choice==2) editStudent();
else if(choice==3) deleteStudent();
else if(choice==4) searchStudent();
else if(choice==5) displayListOfStudents();
if(choice==6) break;
else pressEnterToContinue();
clearTerminal();
}
printf("Bye, Have a good day.\n");
return 0;
}
void printHorizontalLine(char g,int repeat)
{
int i;
for(i=0;i<repeat;i++) printf("%c",g);
}
void clearTerminal()
{
char command[15];
#if _WIN32
strcpy(command,"cls");
#else
strcpy(command,"clear");
#endif
system(command);
}
void clearStdin()
{
#if _WIN32
fflush(stdin);
#elif __LINUX__
__fpurge(stdin);
#else
fpurge(stdin);
#endif
}
void pressEnterToContinue()
{
printf("\nPress enter to continue... .. .");
getchar();
clearStdin();
}
void deleteFile(char *fileName)
{
char command[15];
#if _WIN32
strcpy(command,"remove ");
#else
strcpy(command,"rm ");
#endif
system(strcat(command,fileName));
}
void addStudent()
{
int rollNumber;
char name[32];
char gender[10];
printf("Student (Add Module)\n");
printf("Enter roll number : ");
scanf("%d",&rollNumber);
clearStdin();
if(rollNumber<=0)
{
clearTerminal();
printf("Student (Add Module)\n\n");
printf("Invalid roll number : %d\n",rollNumber);
printf("Note : Roll number cannot be less than or equal to zero\n");
return;
}
FILE *file;
Student student;
file=fopen(STUDENT_DATA_FILE,"rb");
if(file!=NULL)
{
while(1)
{
fread(&student,sizeof(Student),1,file);
if(feof(file)) break;
if(student.rollNumber==rollNumber)
{
fclose(file);
clearTerminal();
printf("Student (Add Module)\n\n");
printf("Roll number allocated to student : %s\n",student.name);
return;
}
}
fclose(file);
}
printf("Enter name : ");
scanf("%[^\n]",name);
clearStdin();
printf("Enter gender (Male/Female): ");
scanf("%[^\n]",gender);
clearStdin();
if(strcasecmp(gender,"male")!=0 && strcasecmp(gender,"female")!=0)
{
clearTerminal();
printf("Student (Add Module)\n\n");
printf("Invalid gender : %s\n",gender);
return;
}
file=fopen(STUDENT_DATA_FILE,"ab");
student.rollNumber=rollNumber;
strcpy(student.name,name);
if(gender[0]=='m' || gender[0]=='M') student.gender='M';
else student.gender='F';
fwrite(&student,sizeof(Student),1,file);
fclose(file);
printf("Student added\n");
}
void editStudent()
{
Student student;
int rollNumber,position,found;
char gender[10];
FILE *file;
printf("Student (Edit Module)\n\n");
printf("Enter rollNumber of the student to be edited : ");
scanf("%d",&rollNumber);
clearStdin();
clearTerminal();
printf("Student (Edit Module)\n\n");
file=fopen(STUDENT_DATA_FILE,"rb");
if(file==NULL)
{
printf("No student exists with roll number : %d\n",rollNumber);
return;
}
found=0;
while(1)
{
position=ftell(file);
fread(&student,sizeof(student),1,file);
if(feof(file)) break;
if(student.rollNumber==rollNumber)
{
found=1;
break;
}
}
fclose(file);
if(!found)
{
printf("No student exists with roll number : %d\n",rollNumber);
return;
}
student.rollNumber=rollNumber;
printf("New details :\n");
printf("Enter name : ");
scanf("%[^\n]",student.name);
clearStdin();
printf("Enter gender (Male/Female): ");
scanf("%[^\n]",gender);
clearStdin();
if(strcasecmp(gender,"male")!=0 && strcasecmp(gender,"female")!=0)
{
clearTerminal();
printf("Student (Edit Module)\n\n");
printf("Invalid gender : %s\n",gender);
return;
}
if(gender[0]=='M' || gender[0]=='m') student.gender='M';
else student.gender='F';
file=fopen(STUDENT_DATA_FILE,"rb+");
fseek(file,position,SEEK_SET);
fwrite(&student,sizeof(student),1,file);
fclose(file);
clearTerminal();
printf("Student (Edit Module)\n\n");
printf("Student record updated\n");
}
void searchStudent()
{
int rollNumber;
Student student;
FILE *file;
printf("Student (Search Module)\n\n");
printf("Enter roll number of the student to be searched : ");
scanf("%d",&rollNumber);
clearStdin();
clearTerminal();
file=fopen(STUDENT_DATA_FILE,"rb");
printf("Student (Search Module)\n\n");
if(file==NULL)
{
printf("Student does not exists with rollNumber : %d\n",rollNumber);
return;
}
while(1)
{
fread(&student,sizeof(Student),1,file);
if(feof(file)) break;
if(student.rollNumber==rollNumber)
{
fclose(file);
printf("Roll Number : %d\n",student.rollNumber);
printf("Name : %s\n",student.name);
printf("Gender : ");
if(student.gender=='M' || student.gender=='m') printf("Male\n");
else printf("Female\n");
return;
}
}
fclose(file);
printf("Student does not exists with rollNumber : %d\n",rollNumber);
}
void deleteStudent()
{
int rollNumber,found;
Student student;
FILE *file,*tmpFile;
printf("Student (Delete Module)\n\n");
printf("Enter roll number of the student to be deleted : ");
scanf("%d",&rollNumber);
clearStdin();
clearTerminal();
file=fopen(STUDENT_DATA_FILE,"rb");
printf("Student (Delete Module)\n\n");
if(file==NULL)
{
printf("Student does not exists with rollNumber : %d\n",rollNumber);
return;
}
tmpFile=fopen("tmp","wb");
found=0;
while(1)
{
fread(&student,sizeof(Student),1,file);
if(feof(file)) break;
if(student.rollNumber!=rollNumber)
{
fwrite(&student,sizeof(Student),1,tmpFile);
}else found=1;
}
fclose(file);
fclose(tmpFile);
if(!found)
{
deleteFile("tmp");
printf("Student does not exists with rollNumber : %d\n",rollNumber);
return;
}
file=fopen(STUDENT_DATA_FILE,"wb");
tmpFile=fopen("tmp","rb");
while(1)
{
fread(&student,sizeof(Student),1,tmpFile);
if(feof(tmpFile)) break;
fwrite(&student,sizeof(Student),1,file);
}
fclose(file);
fclose(tmpFile);
deleteFile("tmp");
printf("Student deleted\n");
}
void displayListOfStudents()
{
Student student;
char gender[10];
int x,size;
FILE *file;
printf("Students List\n\n");
file=fopen(STUDENT_DATA_FILE,"rb");
if(file==NULL)
{
printf("No student added\n");
return;
}
fseek(file,0,SEEK_END);
if(ftell(file)==0)
{
printf("No student added\n");
fclose(file);
return;
}
fseek(file,0,SEEK_SET);
printf("+");
printHorizontalLine('-',15);
printf("+");
printHorizontalLine('-',30);
printf("+");
printHorizontalLine('-',6);
printf("+");
printf("\n");
printf("|%-15s|%-30s|%-6s|\n","Roll Number","Name","Gender");
printf("+");
printHorizontalLine('-',15);
printf("+");
printHorizontalLine('-',30);
printf("+");
printHorizontalLine('-',6);
printf("+");
printf("\n");
while(1)
{
fread(&student,sizeof(Student),1,file);
if(feof(file)) break;
if(student.gender=='M' || student.gender=='m') strcpy(gender,"Male");
else strcpy(gender,"Female");
printf("|%-15d|%-30s|%-6s|\n",student.rollNumber,student.name,gender);
}
fclose(file);
printf("+");
printHorizontalLine('-',15);
printf("+");
printHorizontalLine('-',30);
printf("+");
printHorizontalLine('-',6);
printf("+");
printf("\n");
}
