#include<stdio.h>
struct abc
{
int x,y;
char m;
};
int main()
{
FILE *f;
struct abc g;
g.x=12344;
g.y=98765;
g.m='A';
f=fopen("somefile.fff","wb");
fwrite(&g,sizeof(struct abc),1,f);
fclose(f);
printf("Done\n");
return 0;
}
