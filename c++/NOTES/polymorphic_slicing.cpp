#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class x{
  public:
  int a;
  x(){cout<<"X created"<<endl;}
  virtual void print() const{cout<<"Class x"<<endl;}//const func needed for const object only!!
};

class y: public x{
 public:
 y(){cout<<"Y created"<<endl;}
 void print() const{cout<<"Class y"<<endl;}
};

int main()
{
 //x &t = y();//this does not work since as temporary object gets created for y then copied over to t
 //temporary objects cannot be bound to non-const references!
// const x &t = y(); //works but now the object data cannot be changed.

 y tt;
 x &t = tt;//or x *t has to be used for applying virtual methods
 //this works as no temporary object is created, and just tt's data is copied to t

//x t = tt;//or x t = y(); does not work due to slicing, see bookmark.

 t.print();//prints x::print() and not y::print()
 return 0;
}
