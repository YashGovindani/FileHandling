#include<stdio.h>
#include<string.h>
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
if(this->file)
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
while(!ifs.fail())
{
ifs>>c;
printf("%c",c);
}
ifs.close();
return 0;
}
