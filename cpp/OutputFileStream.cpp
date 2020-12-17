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
if(mode!=OutputFileStream::append && mode!=OutputFileStream::overwrite) return;
if(mode==OutputFileStream::append) this->f=fopen(fileName,"a");
else this->f=fopen(fileName,"w");
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
OutputFileStream & operator<<(string &str)
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
};

int main()
{
string name;
int rollNumber;
std::cout<<"Enter name : ";
getline(std::cin,name);
std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
std::cout<<"Enter roll number : ";
std::cin<<rollNumber;
std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
std::cout<<"Enter gender (M/F): ";
std::cin>>gender;
std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
OutputFileStream ofs("pqr.xyz",OutputFileStream::append);
ofs<<name;
ofs<<'\n';
ofs<<rollNumber;
ofs<<" ";
ofs<<gender;
ofs.close();
return 0;
}
