#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
int add(int a,int b){
//	printf("Sum of a+b is %d\n", a+b); 
	return (a+b); 
}

int sub(int a,int b){
	//printf("Diff of a-b is %d\n", a-b); 
	return (a-b); 
}

int mul(int a,int b){
//	printf("Product of a*b is %d\n", a*b); 
	return (a*b); 
}

typedef int (*OP)(int,int);

int main()
{
  OP *ptr = malloc(3*sizeof(OP));
         ptr[0]=add;
         ptr[1]=sub;
         ptr[2]=mul;
  int a=5,b=4;
  for(int i=0;i<3;i++)
      printf("%d\n",ptr[i](a,b));

  return 0; 
}

