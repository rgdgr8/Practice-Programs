#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
 int t;
 scanf("%d",&t);
 while(t-->0){
  int n;
  scanf("%d",&n);
  char s[n];
  scanf("%s",s);
  int x = n/2;
  int cont = 1;
  char y = s[0];
  for(int i=1;i<n;i++){
     if(y!=s[i]){
       cont = 1;
       y = s[i];
     }else
       cont++;
     if(cont==x)break;
  }
  //printf("cont=%d\n",cont);
  if(cont==x)
     x = x-1;
  else
     x = x/2;
  printf("%d\n",x);
 } 
 return 0;
}
