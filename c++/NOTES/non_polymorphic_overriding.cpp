#include <iostream>
using namespace std;

class x{
  public:
  void printx(double a,int x) {cout<<"Class x"<<endl;}//const func needed for const object only!!
};

class y: public x{
 public:
 void print(char a) {cout<<"Class y char: "<<a<<endl;}
};

int main()
{
 y t;
 t.print(-3);
 t.printx(1.0,2); //Does not work, if function name matched in derived class, it will not look in parent, even if the matched function can't be executed. ******NOT APPLICABLE FOR POLYMORPHISM************
 return 0;
}
