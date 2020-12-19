#include<stdio.h>
#include<string.h>
class InputFileStream
{
private:
FILE *f;
int lastOperationFailed;
public:
const static int read=1;
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
this->open(fileName);
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
if(mode!=read && mode!=(read | binary)) return;
if(!fileName) return;
this->mode=mode;
if(mode==read) this->f=fopen(fileName,"r");
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
