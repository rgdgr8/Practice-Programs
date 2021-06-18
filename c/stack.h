#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  char v;
  struct node* next;
}node;

typedef struct stack{
  node *head;
}stack;

void push(stack *s,char v){
  node* n = malloc(sizeof(node));
  n->v = v;
  n->next = s->head;
  s->head = n;
}

int is_empty(stack s){
   if(s.head == NULL)
      return 1;
   return 0;
}

char get_top(stack s){
   if(is_empty(s)){
     printf("Stack is empty already!\n");
     return -1;
   }
   
   return s.head->v;
}

char pop(stack *s){
  if(is_empty(*s)){
     printf("Stack is empty already!\n");
     return -1;
  }
     
  node *t = s->head;
  char tc = t->v;
  s->head = s->head->next;
  free(t);
  return tc;
}

void print_stack(stack s){
  for(;s.head!=NULL;s.head=s.head->next)
     printf("%c ",s.head->v);
  printf("\n");
}
