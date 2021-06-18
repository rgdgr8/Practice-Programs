#include<stdio.h>
int main()
{
 int A[] = {1,2,3,4,5};
 for(int i=0;i<5;i++){
    printf("addr= %lu\t\t",(unsigned long)A+i);
    printf("val= %d\n",*(A+i));
    printf("addr= %p\t\t",&A[i]);
    printf("val= %d\n",A[i]);
    printf("&arr=%p\n",&A);
    printf("sizeof(arr)=%lu\n\n",sizeof(A));
 }
 return 0;
}
