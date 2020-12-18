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
public:
InputFileStream()
{
this->f=NULL;
this->lastOperationFailed=0;
}
InputFileStream(const char *fileName)
{
this->lastOperationFailed=0;
this->f=NULL;
this->open(fileName);
}
void open(const char *fileName)
{
if(this->f)
{
fclose(this->f);
this->lastOperationFailed=0;
}
this->lastOperationFailed=1;
if(!fileName) return;
this->f=fopen(fileName,"r");
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
void close()
{
this->lastOperationFailed=0;
if(this->f) fclose(this->f);
}
};
int main()
{
char c;
InputFileStream ifs("pqr.xyz");
while(1)
{
ifs>>c;
if(ifs.fail()) break;
printf("%c",c);
}
ifs.close();
return 0;
}
