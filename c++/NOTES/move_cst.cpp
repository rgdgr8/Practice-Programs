#include <iostream>
#include <vector>
using namespace std;

class X{
 public:
  int a;
  X():a(5){cout<<"X default cst"<<endl;}
  X(const X& x){a=x.a;cout<<"X copy cst"<<endl;}
  X(X&& x){a=x.a;cout<<"X move cst"<<endl;}
};

class Y{
 public:
  X x;
  int b;
  Y():b(9){cout<<"Y default cst"<<endl;}
  Y(Y&& y):x(move(y.x)/* try with and without move() on y.x */),b(y.b){cout<<"Y move cst"<<endl;}
};

int main(){
 Y a;
 Y b = move(a);
 return 0;
}
