#include <iostream>
#include <vector>
#include <string>
using namespace std;
class X{
  public:
  int *a;
  int b;
  X(){}
  X(int a,int b=0):b(b){this->a = new int(a);}
};

int main(){
 X a(1,2);
 cout<<"a="<<a.a<<endl;
 X c = move(a);
 cout<<"a="<<a.a<<endl;
 cout<<a.b<<endl;
 cout<<"c="<<c.a<<endl;
 cout<<c.b<<endl;
 return 0;
}
