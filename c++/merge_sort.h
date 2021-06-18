template<class T>
void merge(T data[],int start,int m,int end){
  int i=0,j=0,k=start;
  int x_size = (m-start+1);
  int y_size = end-m;
  T x[x_size];
  T y[y_size];
  
  for(int l=0;l<x_size;l++){
     x[l] = data[start+l];
  }
  for(int n=0;n<y_size;n++){
     y[n] = data[(m+1+n)];
  }

  while(i<x_size && j<y_size){
       if(x[i]>y[j])
         data[k++] = y[j++];
       else
         data[k++] = x[i++];
  }
  
  while(i<x_size)
     data[k++] = x[i++];
  while(j<y_size)
     data[k++] = y[j++];
}
template<class T>
void sort(T data[],int start,int end){
  if(start>=end)
    return;
  
  int m = (start+end)/2;
  sort(data,start,m);
  sort(data,m+1,end);
  merge(data,start,m,end);
}
