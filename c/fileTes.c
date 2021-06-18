#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[])
{
 FILE *read = fopen(argv[1],"r");
 FILE *w = fopen(argv[2],"r");
 int first;
 char *f;
 fscanf(read,"%s",&*f);
 fscanf(read,"%d",&first);//read first number in the file
 puts(f);
 printf("%d",first);
 return 0;
}
