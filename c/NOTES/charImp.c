#include<stdio.h>
int main(void)
{
 char *s = "ola";
 printf("%lu\n",sizeof(s));
 s="kola";//note!
 printf("%lu\n",sizeof(s));
// *s='a';this is wrong, char * is a string LITERAL and though the entire value can be change but a particular position cannot be!

// printf("%s",s); better method to print string.
 for(int i=0;*(s+i)!='\0';i++)
     printf("%c",*(s+i));//note!
 return 0;
}
