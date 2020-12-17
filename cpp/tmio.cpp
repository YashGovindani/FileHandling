#include<stdio.h>
class OutputFileStream
{
private:
FILE *f;
int mode;
public:
const static int append=1;
OutputFileStream()
{
this->f=NULL;
this->mode=-1;
}
OutputFileStream(const char *fileName,int mode)
{
this->f=NULL;
this->open(fileName,mode);
}
void open(const char *fileName,int mode)
{
if(f!=NULL)
{
fclose(f);
this->f=NULL;
this->mode=-1;
}
if(fileName==NULL)
{

}
}
};
