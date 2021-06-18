#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct student{
 int roll;
 char name[50];
 int score[3]; 
}student;

const char* names[] = {"a","b","c","d","e","f","g","h","i","j"};

int comp(const void* m, const void* n){
   int x,y;
   const student* a = (const student*)m;
   const student* b = (const student*)n;

   x = a->score[0] + a->score[1] + a->score[2];
   y = b->score[0] + b->score[1] + b->score[2];

   return x-y;
}

int main()
{
 student s[5];
 for(int i=0;i<5;i++){
    s[i].roll = (i+1);
    strcpy(s[i].name,names[i]);
    s[i].score[0] = i*10;
    s[i].score[1] = i*20;
    s[i].score[2] = i*30;
 }
 
 qsort(s,5,sizeof(student),comp);
 for(int i=0;i<5;i++){
    printf("Name = %s, Roll = %d\n",s[i].name,s[i].roll);
    printf("Score1 = %d\n",s[i].score[0]);
    printf("Score2 = %d\n",s[i].score[1]);
    printf("Score3 = %d\n",s[i].score[2]);
 }
}
