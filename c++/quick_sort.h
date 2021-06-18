#include <cstdlib>
#include <ctime>
#include <cassert>

int n = 0;

void print(int arr[]){
 for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
 cout<<endl;
}

template<class T>
void swap(T arr[],int i,int j){
  T t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}
template<class T>
void quicksort(T arr[],int l,int r){
  if(n<=0){
    n = r-l+1;
    assert(n>0);
    srand(time(0));
  }
 // cout<<"l="<<l<<" r="<<r<<endl;
  if(l>=r)
    return;
  int pivot_i = rand()%(r-l+1)+l;
  T pivot = arr[pivot_i];
  //cout<<"pivot_i="<<pivot_i<<" pivot="<<pivot<<endl;
  swap(arr,pivot_i,l);
  int smaller = l;
  int smaller_count = 0;
  int same = l;
  int same_count = 1;
  for(int i=l+1;i<=r;i++){
     if(arr[i]<pivot){
       smaller++;
       smaller_count++;
       if(smaller!=i)
         swap(arr,smaller,i);
     }else if(arr[i]==pivot){
       same++;
       same_count++;
       if(same!=i){
         swap(arr,same,i);
         i--;
         if(arr[i]<pivot)
            smaller_count--;
       }
     }
  }
 // cout<<"After swap: same="<<same<<" smaller="<<smaller<<endl<<"smaller_count="<<smaller_count<<" same_count="<<same_count<<endl;
  
  int t = l;
  int smt = smaller;
  while(t<=same && smt>same){
    swap(t,smt);
    smt--;t++;
  }

  int r1 = l+smaller_count-1;
  int l2 = r1+1+same_count;
  quicksort(arr,l,r1);
  quicksort(arr,l2,r);
}
