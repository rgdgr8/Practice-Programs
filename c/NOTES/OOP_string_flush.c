#include<stdio.h>
#include<stdlib.h>
#include<math.h>

FILE *fp;

void readfp(long long *r, char *s){
 fscanf(fp,"%lld",r);
 for(int i=1;i<3;i++)
    getc(fp);
 fscanf(fp,"%[^\n]%*c",s);
   //fgets(s,100,fp);
}

int main()
{
 fp = fopen("nameroll.txt","r");
 FILE *fp2 = fopen("mates.txt","w");
 char *s = malloc(100);
 long long r;
 readfp(&r,s);//MACOS DOES NOT READ AHEAD HENCE THIS APPROACH.
 while(!feof(fp)){
   fprintf(fp2,"%s 00%lld\n",s,r);//THIS WORKS PROPERLY, YET!!!!!!!! 
   //printf("%s %lld\n",s,r); THIS DOES NOT!


/*-----ONLY PUTTING \n AFTER %s FLUSHES OUT BUFFERE, PUTTING \n AFTER %lld DOES NOT FLUSH STRING PROPERLY-----------*/ 
   printf("00%lld %s\n",r,s); 
   //printf("%s\n %lld\n",s,r); WORKS BUT IF ONLY IF THIS ORDER IS DESIRED.
   readfp(&r,s);
 }
 return 0;
}
