#include <iostream>
#include <vector>
using namespace std;

void foo2(int&& x){
 cout<<x<<endl;
}

void foo1(int&& x){
  foo2(x);
}

int main(){
 int&& x = 9;
 foo1(x);
 return 0;
}

/* rvalue references after intialized/defined are treated as lvalues by the compiler!!!!*/
