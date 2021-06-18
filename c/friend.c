#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
 int n;
 scanf("%d",&n);
 int third[n];
 int fourth[n];
 for(int i=0;i<n;i++){
    scanf("%d",&third[i]);
 }
 for(int i=0;i<n;i++){
    scanf("%d",&fourth[i]);
 }
 int friends[n];
 for(int i=0;i<n;i++){
    int x = third[i]-1;
//    printf("third[%d] = %d fourth[%d] = %d\n",i,third[i],i,fourth[i]);
    friends[x] = fourth[i];
 }
 for(int i=0;i<n;i++)
    printf("%d ",friends[i]);
 return 0;
}
