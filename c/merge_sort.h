#include<string.h>

void merge(char *data[],int start,int m,int end){
  int i=0,j=0,k=start;
 // printf("start = %d, m = %d, end = %d\n",start,m,end);
  int x_size = (m-start+1);
  int y_size = end-m;
  char *x[x_size];
  char *y[y_size];
  
  for(int l=0;l<x_size;l++){
    // printf("l=%d  start+i=%d\n",l,(start+i));
     x[l] = data[start+l];
    // printf("%s\n",x[l]);
  }
  for(int n=0;n<y_size;n++){
    // printf("n=%d  m+1+n=%d\n",n,(m+1+n));
     y[n] = data[(m+1+n)];
    // printf("%s\n",y[n]);
  }

  while(i<x_size && j<y_size){
       if(strcmp(x[i],y[j])>0)
         data[k++] = y[j++];
       else
         data[k++] = x[i++];
  }
  
  while(i<x_size)
     data[k++] = x[i++];
  while(j<y_size)
     data[k++] = y[j++];
}
void sort(char *data[],int start,int end){
  if(start>=end)
    return;
  
  int m = (start+end)/2;
  sort(data,start,m);
  sort(data,m+1,end);
  merge(data,start,m,end);
}
