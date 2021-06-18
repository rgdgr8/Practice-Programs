#include<stdio.h> 
int main() 
{ 
 int a = 3;
 int *p;//contains garbage address by default
 *p = 3;//will work but, may lead to error often.
 printf("%p\n",p);
 printf("%d\n",*p);
 return 0;
} 
