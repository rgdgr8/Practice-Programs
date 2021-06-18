#include<stdio.h>
int main(void)
{
 int c;
 while((c=getchar())!=EOF){
 printf("%c is %d\n",c,c);
 } 
 return 0;
}
