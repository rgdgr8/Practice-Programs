#include <iostream>
using namespace std;

class x{
  public:
  virtual void print(double a) {cout<<"Class x double"<<endl;}//const func needed for const object only!!
  virtual void print(int a) {cout<<"Class x int"<<endl;}//const func needed for const object only!!
};

class y: public x{
 public:
 void print(double a) override {cout<<"Class y double"<<endl;}
 void print(char a) {cout<<"Class y char"<<endl;}
};

int main()
{
 x *t = new y();//In this case, I speculate that all functions are as if merged into the same class, hence overloading is possible even across base and derived classes!

 //y *t = new y(); //try this as well
 t->print(1);
 return 0;
}
