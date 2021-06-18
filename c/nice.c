#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
 int x; 
 scanf("%d",&x);
 int even = 0;
 int odd = 0;
 for(int i=1;i<=x;i++)
    if(x%i==0){
       if(i%2==0)
         even++;
       else
         odd++;
    }
 if(odd==even)
    printf("yes");
 else
    printf("no");
 
 return 0;
}
