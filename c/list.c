#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct list{
 int data;
 struct list *next;
}list;

void add(int d,list **h){
 list *head = malloc(sizeof(list));
 head->data = d;
 head->next = *h;
 *h = head;
 //return head;
}

void swap(list *curr, list *sorter){
 int t = curr->data;
 curr->data = sorter->data;
 sorter->data = t;
}

void sort(list *h){//using selection sort and not bubble sort.
 list *curr = h;
 while(curr!=NULL){
     list *sorter = curr->next;
     while(sorter!=NULL){
          if(sorter->data<curr->data)
            swap(curr,sorter);
         sorter = sorter->next;
     }
     curr = curr->next;
 }
}

void remove_duplicates(list *h){//extra function to remove duplicate elements
 list *curr = h;
 while(curr!=NULL && curr->next!=NULL){//if current node is null or if it is the last node,exit.
      if(curr->data==curr->next->data){
         list *ptr = curr->next;
         curr->next = curr->next->next;//if 2 adjacent nodes are equal then change the next ptr
         free(ptr);
      }else
         curr = curr->next;
 }
}

void print_list(list *head){
 int col = 0;
 while(head!=NULL){
      printf("%d\t",head->data);
      col++;
      head = head->next;
      if(col==5){//for printing no more than 5 ints in a row
        printf("\n");
        col = 0;
      }
 }
}

int main()
{ 
 list *head = malloc(sizeof(list));
 head->data = 1;//create and initialize list
 head->next = NULL;
 for(int i=2;i<101;i++){
   add(rand()%100,&head);
  // printf("head value after %d is %d\n",i,head->data);------ line for debugging
 }
 sort(head);
 remove_duplicates(head);//----used to remove duplicates, not needed here.
 print_list(head);
 return 0;
}
