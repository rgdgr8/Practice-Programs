#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 200001
char *s;
 
int get(int x){
    switch(x){
          case 65: return 1;
          case 67: return 2;
          case 71: return 3;
          case 84: return 4;
          case 36: return 0;
         // case 66: return 2;
          default: return -1;
    }
}

void print(int a[],int size){
 for(int i=0;i<size;i++)
    printf("%d ",a[i]);
}

void initialize(int order[],int class[],int size){
 int count[5] = {0,0,0,0,0};
 for(int i=0;i<size;i++){
    int y = get(s[i]);
    count[y]++;
    class[i] = y;
 }
 for(int j=1;j<5;j++){
      count[j]+= count[j-1];
 }
/* print(count,5);
 printf("\n");
 print(class,size);
 printf("\n");*/
 for(int i=size-1;i>=0;i--){
    int y = get(s[i]);
    int x = --count[y];
    order[x] = i;
 }
// print(order,size);
} 

void sortL(int order[],int class[],int size,int L){
 int count[size];int new_order[size];int new_class[size];
 for(int i=0;i<size;i++)
    count[i] = 0;
 for(int i=0;i<size;i++)
    count[class[i]]++;
 for(int j=1;j<size;j++){
    count[j]+= count[j-1];
 }
 for(int i=size-1;i>=0;i--){
    int start = (order[i]-L+size)%size;
    int index = --count[class[start]];
 //   printf("i=%d,start=%d,index=%d\n",i,start,index);
    new_order[index] = start;
 }
 
// printf("new_class new_order[0]: %d\n",new_order[0]);
 new_class[new_order[0]] = 0;
 for(int i=1;i<size;i++){
    int curr = new_order[i]; int prev = new_order[i-1];
    int mid = (curr + L)%size; int midprev = (prev+L)%size;
  //  printf("i=%d,curr=%d,prev=%d,mid=%d,midprev=%d\n",i,curr,prev,mid,midprev);
    if(class[curr]==class[prev] && class[mid]==class[midprev])
      new_class[curr] = new_class[prev];
    else
      new_class[curr] = new_class[prev] + 1;
 }

 for(int i=0;i<size;i++){
    order[i] = new_order[i];
    class[i] = new_class[i];
 }
} 

int main()
{ 
 s = malloc(max);
 scanf("%s",s);
 int size = strlen(s);
 int order[size];
 int class[size];
 initialize(order,class,size);
 int L = 1;
 while(L<size){
  sortL(order,class,size,L);
  L*=2;
 }
 print(order,size);
 return 0;
}
