#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{ 
 char *c = malloc(101);
 scanf("%s",c);
 int vowels = 0;
 int init_size = 1;
 for(int i=0;c[i]!='\0';i++){
    if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u' || c[i]=='y' || c[i]=='A' || c[i]=='E' || c[i]=='I' || c[i]=='O' || c[i]=='U' || c[i]=='Y'){
      c[i] = '$';
      vowels++;
    }
    init_size++;
 }
 char s[2*(init_size-vowels)];
 int j=0;
 for(int i=0;c[i]!='\0';i++){
    if(c[i] == '$')
      continue;

    if(isupper(c[i]))
      c[i] = c[i] + 32;
    
    s[j++] = '.';
    s[j++] = c[i];
    printf(".%c",c[i]); 
 }
     
 return 0;
}
