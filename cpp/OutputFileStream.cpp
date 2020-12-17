#include<stdio.h>
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
if(f)
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
OutputFileStream & operator<<(char *str)
{
int i;
this->lastOperationFailed=1;
if(!this->f) return *this;
if(!str) return *this;
for(i=0;i<sizeof(str);i++) fputc(str[i],this->f);
this->lastOperationFailed=0;
return *this;
}
};
