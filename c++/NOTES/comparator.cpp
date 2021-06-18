#include <iostream>
using namespace std;

class X{
  public:
  int i;
  char c;
  
  bool operator>(const X& x) const {return i>x.i;}//this function has to be all const if greater<X> is used due to the implementation of greater<T> class
  
  bool operator<(const X& x) const {return i<x.i;}
};

//For custom comparator functions we can make or not make anything const or not as we like
bool grtr(X& a,X& b){return a.i>b.i;}

class grtr_than{
  public:
  bool operator()(X& a,X& b){return a.i>b.i;}
};

int main()
{
 X y = {3,'c'};
 X z = {5,'e'};
 X x[2] = {y,z};
 
 sort(x,x+2,greater<X>());
 cout<<x[0].i<<"  "<<x[0].c<<endl;
 cout<<x[1].i<<"  "<<x[1].c<<endl;
 
 sort(x,x+2,grtr_than());
 cout<<x[0].i<<"  "<<x[0].c<<endl;
 cout<<x[1].i<<"  "<<x[1].c<<endl;
 
 sort(x,x+2);
 cout<<x[0].i<<"  "<<x[0].c<<endl;
 cout<<x[1].i<<"  "<<x[1].c<<endl;
}

