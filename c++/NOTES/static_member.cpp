#include <iostream>
#include <string>
#include <string.h>
using namespace std;

static int x;

class A{
 public:
  static int a;
  A(){  
   a++;
  }
};
int A::a = 10;//important
int main()
{
 A y;
 A z;
 cout<<x<<endl;
 cout<<A::a<<endl;
 return 0;
}
