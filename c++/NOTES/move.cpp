#include <iostream>
#include <vector>
using namespace std;

class X{
  public:
  int *x;
  int size;
  X(){x = new int[3];size = 3;}

  //the container from which resources are moved are actually not emptied, but the size field is
  //zeroed(as in this case or in the case of vectors, for example).

  X(X&& v){
    x = v.x;
    size = 3;
    v.x = nullptr;//try without 
    v.size = 0;//these two lines
    cout<<"Move cst"<<endl;
  }
  X& operator=(X&& v){
    delete []x;
    x = v.x;
    size = 3;
    v.x = nullptr;//try without 
    v.size = 0;//these two lines
    cout<<"Move oper"<<endl;
    return *this;
  }
  //~X(){if(x!=nullptr)delete []x;}
};

void print(const X &x){
  for(int i=0;i<x.size/*3*/;i++)
      cout<<x.x[i]<<" ";
  cout<<endl;
}

int main(){
 X a;
 for(int i=0;i<3;i++){
    a.x[i] = i;
 }
 X b;
 for(int i=10;i<13;i++){
    b.x[i-10] = i;
 }
 cout<<"Before move:"<<endl<<"a: "<<a.x<<endl;print(a);cout<<"b: "<<b.x<<endl;print(b);
 a = move(b);
 cout<<"After move to a from b:"<<endl<<"a: "<<a.x<<endl;print(a);cout<<"b: "<<b.x<<endl;print(b);
 X c(move(a));
 cout<<"After move to c from a:"<<endl<<"c: "<<c.x<<endl;print(c);cout<<"a: "<<a.x<<endl;print(a);
 b = move(c);
 cout<<"After move to b from c:"<<endl<<"b: "<<b.x<<endl;print(b);cout<<"c: "<<c.x<<endl;print(c);
 return 0;
}
