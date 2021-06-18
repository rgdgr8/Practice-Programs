#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000002
void build_prefix(char *ps,unsigned int p_array[]);
 int main()
{
 char *p = malloc(MAX);
 char *s = malloc(MAX);
 scanf("%s",p);
 scanf("%s",s);
 unsigned int max_size = strlen(p)+strlen(s)+2;
 char ps[max_size];
// char *ps = malloc(max_size);//Here we MUST use malloc instead of array, becoz ps gets passed
 unsigned int j = 0;         //to another function, and for array declaration the memory is
 for(int i=0;p[i]!='\0';i++){//visible only in the particular stack (i.e. within its scope,
    ps[i] = p[i];            //i.e main()),while for malloc,the storage is dynamic and hence
    j = i;                   //it's memory is visible in the entire program.
 }
 free(p);
 unsigned int p_size = j+1;
 ps[++j] = '$';
 unsigned int dollar_size = j+1;
 for(int i=0;s[i]!='\0';i++)
    ps[++j] = s[i];
 ps[++j] = '\0';
 free(s);
// puts(ps); 
// printf("dollar=%d, p=%d\n",dollar_size,p_size);
// unsigned int s_size = j - dollar_size;
// free(ps);
 unsigned int p_array[j];
 build_prefix(ps,p_array);
 for(int i=dollar_size;i<j;i++){
    if(p_array[i] == p_size)
       printf("%d ",(i-2*p_size));
 }
 return 0;
}
void build_prefix(char ps[],unsigned int p_array[]){
 p_array[0] = 0;
 unsigned int border = 0;
 for(int i=1;ps[i]!='\0';i++){
    while(border>0 && ps[i]!=ps[border])
         border = p_array[border-1];
    if(ps[i]==ps[border])
      border++;
    else
      border = 0;
    p_array[i] = border;
 }
// for(int i=0;ps[i]!='\0';i++)
  //  printf("%d ",p_array[i]);
}
