#include<stdio.h>
 
int main() 
{ 
 int *p; 
 int (*ptr)[5];//Just a declaration, no space is allocated yet!!! 
 int arr[5]; 
 printf("sizeof(arr)=%lu\n",sizeof(arr));
 printf("sizeof(ptr)=%lu\n",sizeof(ptr));
 printf("sizeof(*ptr)=%lu\n",sizeof(*ptr));
 p = arr;
 // Points to the whole array arr. 
 ptr = &arr; 
 int *x = *ptr;

 printf("p = %p, ptr = %p\n", p, ptr); 
 printf("(ptr+1)-ptr=%ld\n",(ptr+1)-ptr); //gets auto casted to long when doing operation
 p++;
 ptr++;
 printf("p = %p, ptr = %p\n", p, ptr); 

 printf("(int)(ptr(new))-(int)ptr=%d\n",(int)(*ptr)-(int)x);
 printf("(ptr(new))-ptr=%ld\n",*ptr-x);//gives value divided by sizeof(type) 
 return 0; 
} 
