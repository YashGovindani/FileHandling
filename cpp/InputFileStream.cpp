#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<limits>
#include<ios>
class InputFileStream
{
private:
FILE *f;
int lastOperationFailed;
int mode;
public:
const static int reading=1;
const static int binary=4;
InputFileStream()
{
this->mode=-1;
this->f=NULL;
this->lastOperationFailed=0;
}
InputFileStream(const char *fileName)
{
this->mode=-1;
this->lastOperationFailed=0;
this->f=NULL;
this->open(fileName,reading);
}
InputFileStream(const char *fileName,int mode)
{
this->mode=-1;
this->lastOperationFailed=0;
this->f=NULL;
this->open(fileName,mode);
}
void open(const char *fileName,int mode)
{
if(this->f)
{
fclose(this->f);
this->lastOperationFailed=0;
}
this->lastOperationFailed=1;
if(mode!=reading && mode!=(reading | binary)) return;
if(!fileName) return;
this->mode=mode;
if(mode==reading) this->f=fopen(fileName,"r");
else this->f=fopen(fileName,"rb");
if(!this->f) return;
this->lastOperationFailed=0;
}
int fail()
{
return this->lastOperationFailed;
}
InputFileStream & operator>>(char &c)
{
this->lastOperationFailed=1;
if(!this->f) return *this;
if(feof(this->f)) return *this;
c=fgetc(this->f);
if(feof(this->f)) return *this;
this->lastOperationFailed=0;
return *this;
}
InputFileStream & operator>>(char *str)
{
char g;
char *p;
int i;
this->lastOperationFailed=1;
if(!this->f) return *this;
if(feof(this->f)) return *this;
p=str;
i=0;
while(1)
{
g=fgetc(this->f);
if(g=='\n' || feof(this->f)) break;
*p=g;
++p;
}
*p='\0';
this->lastOperationFailed=0;
return *this;
}
InputFileStream & operator>>(std::string &str)
{
char g;
this->lastOperationFailed=1;
if(!this->f) return *this;
if(feof(this->f)) return *this;
str.clear();
while(1)
{
g=fgetc(this->f);
if(g=='\n' || feof(this->f)) break;
str.push_back(g);
}
this->lastOperationFailed=0;
return *this;
}
InputFileStream & operator>>(int &num)
{
char a[21];
char g;
int i;
this->lastOperationFailed=1;
if(!this->f) return *this;
if(feof(this->f)) return *this;
i=0;
while(1)
{
g=fgetc(this->f);
if(g=='\n' || g==' ' || feof(this->f)) break;
a[i++]=g;
}
if(i==0) return *this;
a[i]='\0';
this->lastOperationFailed=0;
num=atoi(a);
return *this;
}
void read(void *stream,unsigned long size)
{
this->lastOperationFailed=1;
if(!this->f) return;
if(size<1) return;
if(feof(this->f)) return;
fread((char *)stream,size,1,this->f);
if(!feof(this->f))this->lastOperationFailed=0;
}
void close()
{
this->lastOperationFailed=0;
if(this->f) fclose(this->f);
}
};
class Student
{
private:
int rollNumber;
std::string name;
char gender;
public:
Student()
{
this->rollNumber=0;
this->name.clear();
this->gender='\0';
}
Student(int rollNumber,std::string &name,char gender)
{
this->rollNumber=rollNumber;
this->name=name;
this->gender=gender;
}
void setRollNumber(int rollNumber)
{
this->rollNumber=rollNumber;
}
int getRollNumber()
{
return this->rollNumber;
}
void setName(std::string &name)
{
this->name=name;
}
std::string & getName()
{
return this->name;
}
void setGender(char gender)
{
this->gender=gender;
}
char getGender()
{
return this->gender;
}
};
int main()
{
char c;
InputFileStream ifs("pqr.xyz");
std::string name;
int rollNumber;
char gender;
ifs>>name;
ifs>>rollNumber;
ifs>>gender;
std::cout<<"Name : "<<name<<std::endl;
std::cout<<"Roll Number : "<<rollNumber<<std::endl;
std::cout<<"Gender : "<<gender<<std::endl;
ifs.close();
Student student;
ifs.open("xyz.pqr",InputFileStream::reading| InputFileStream::binary);
ifs.read(&student,sizeof(student));
std::cout<<"Name : "<<student.getName()<<std::endl;
std::cout<<"Roll Number : "<<student.getRollNumber()<<std::endl;
std::cout<<"Gender : "<<student.getGender()<<std::endl;
ifs.close();
return 0;
}
