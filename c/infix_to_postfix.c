#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack.h"

int is_operand(char c){
   if((c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57))
      return 1;
   return 0;
}

/* pop stack while isp>=icp */

int isp(char c){
  switch(c){
     case '(' : return 0;
     case '^' : return 3;
     case '/' : return 2;
     case '*' : return 2;
     case '+' : return 1;
     case '-' : return 1;
     default : return -1;
  }
}

int icp(char c){
  switch(c){
     case '(' : return 5;
     case '^' : return 4;
     case '/' : return 2;
     case '*' : return 2;
     case '+' : return 1;
     case '-' : return 1;
     default  : return 6;//default value is always greater than isp!
  }
}

void infix_to_postfix(char *e){
  stack s = {NULL};
  int size = strlen(e);
  char postfix[size+1];int ind = 0;
  for(int i=0;i<size;i++){
     char c = e[i];
     //printf("char= %c\n",c);
     if(is_operand(c))
        postfix[ind++] = c;
     else if(c==')'){
        c = pop(&s);
        while(c!='('){
             postfix[ind++] = c;
             c = pop(&s);
        }
     }else{
        char tc = get_top(s);
        while(isp(tc)>=icp(c)){
             postfix[ind++] = tc;
             pop(&s);
             tc = get_top(s);
        }
        push(&s,c);
     }
     //printf("postfix= %s\n",postfix);
  }
  while(!is_empty(s)){
    postfix[ind++] = pop(&s);
  }
  postfix[ind] = '\0';
  printf("%s\n",postfix);
}

int main()
{
 char *s = malloc(100);
 printf("Enter an expression: ");
 scanf("%s",s);
 infix_to_postfix(s);
}
