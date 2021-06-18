#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
 int t;
 scanf("%d",&t);
 while(t-->0){
  long long l,r;
  scanf("%lld %lld",&l,&r);
  double x = r/2.0;
  if(l<=x)
    printf("NO");
  else
    printf("YES");
  printf("\n");
 } 
 return 0;
}
