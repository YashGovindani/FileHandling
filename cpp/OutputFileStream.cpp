#include<stdio.h>
#include<iostream>
#include<string.h>
#include<limits>
#include<ios>
class OutputFileStream
{
private:
FILE *f;
int mode;
int lastOperationFailed;
public:
const static int append=1;
const static int overwrite=2;
const static int binary=4;
OutputFileStream()
{
this->f=NULL;
this->mode=-1;
this->lastOperationFailed=0;
}
OutputFileStream(const char *fileName,int mode)
{
this->f=NULL;
this->lastOperationFailed=0;
this->open(fileName,mode);
}
void open(const char *fileName,int mode)
{
if(this->f)
{
fclose(this->f);
this->f=NULL;
this->mode=-1;
}
this->lastOperationFailed=1;
if(!fileName) return;
if(mode!=append && mode!=overwrite && mode!=(append | binary) && mode!=(overwrite | binary)) return;
if(mode==OutputFileStream::append) this->f=fopen(fileName,"a");
else if(mode==overwrite) this->f=fopen(fileName,"w");
else if(mode==((overwrite | binary))) this->f=fopen(fileName,"wb");
else this->f=fopen(fileName,"ab");
if(!this->f) return;
this->lastOperationFailed=0;
}
void close()
{
this->lastOperationFailed=0;
if(!this->f) return;
fclose(this->f);
}
int fail()
{
return this->lastOperationFailed;
}
OutputFileStream & operator<<(char c)
{
this->lastOperationFailed=1;
if(!this->f) return *this;
fputc(c,this->f);
this->lastOperationFailed=0;
return *this;
}
OutputFileStream & operator<<(const char *str)
{
this->lastOperationFailed=1;
if(!this->f) return *this;
if(!str) return *this;
fputs(str,this->f);
this->lastOperationFailed=0;
return *this;
}
OutputFileStream & operator<<(std::string &str)
{
this->lastOperationFailed=1;
if(!this->f) return *this;
fputs(str.c_str(),this->f);
this->lastOperationFailed=0;
return *this;
}
OutputFileStream & operator<<(int num)
{
char str[21];
sprintf(str,"%d",num);
this->lastOperationFailed=1;
if(!this->f) return *this;
fputs(str,this->f);
this->lastOperationFailed=0;
return *this;
}
void write(void *ptr,unsigned long size)
{
this->lastOperationFailed=1;
if(!ptr) return;
if(size<1) return;
fwrite((const char *)ptr,size,1,f);
this->lastOperationFailed=0;
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
std::string name;
int rollNumber;
char gender;
std::cout<<"Enter name : ";
getline(std::cin,name);
std::cout<<"Enter roll number : ";
std::cin>>rollNumber;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
std::cout<<"Enter gender (M/F): ";
std::cin>>gender;
OutputFileStream ofs("pqr.xyz",OutputFileStream::overwrite);
ofs<<name;
ofs<<'\n';
ofs<<rollNumber;
ofs<<" ";
ofs<<gender;
ofs.close();
ofs.open("xyz.pqr",OutputFileStream::append | OutputFileStream::binary);
Student student(rollNumber,name,gender);
ofs.write(&student,sizeof(student));
ofs.close();
return 0;
}
