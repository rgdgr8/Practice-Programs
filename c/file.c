#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
int main(int argc, char *argv[])
{
 assert(argc==3);
 FILE *read = fopen(argv[1],"r");
 FILE *write = fopen(argv[2],"w");
 int first;
 fscanf(read,"%d",&first);//read first number in the file
 assert(first>0);
 int data[first];

 rewind(read);
 int read_int;
 int index=0;
 double sum = 0.0;
 while(fscanf(read,"%d",&read_int)==1 && index<first){//filling array and calculating sum
      data[index++]=read_int;
      sum+=read_int;
 }
 double avg = sum/first;//average of the read numbers
 
 printf("The first %d number(s) in the file is/are:\n",first);
 int max = -1;
 for(int i=0;i<first;i++){//finding maximum number and printing array
    if(data[i]>max)
       max = data[i];
    printf("%d\t",data[i]);
    fprintf(write,"%d ",data[i]);//print in the output file
    if(i!=0 && i%5==0){//for output decoration
      printf("\n");
      fprintf(write,"\n");
    }
 }
 
 printf("\nAverage is: %.3lf\n",avg);
 printf("Maximum is: %d\n",max);
 fprintf(write,"\nAverage is: %.3lf\n",avg);
 fprintf(write,"Maximum is: %d\n",max);
 
 fclose(read);
 fclose(write);
 return 0;
}
