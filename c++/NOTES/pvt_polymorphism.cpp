#include <iostream>
using namespace std;

class p{
 // virtual void foo(){cout<<"parent"<<endl;}// try this in public and private
  public:
  virtual void foo(){cout<<"parent"<<endl;}
  void foobar(){cout<<"pfoo"<<endl;foo();}//try with and without this
};

class d : public p{
  private:
  void foo(){cout<<"derived"<<endl;}
  public: 
  void foobar(){cout<<"dfoo"<<endl;foo();}
};

int main()
{
 //d *t = new d();
 p *t = new d();
 //t->foobar();
 t->foo();//try this and foobar()
 return 0;
}

/* 
Case 1: foo() is public in p and no foobar() in p and t->foo()
     
a) with d *t, error as foo() is pvt
b) with p *t, output: derived (parent object does not realise access specifier in child class

Case 2: same as 1 but with t->foobar()

a) derived
b) error, parent object cant look outside p and p has no foobar()

Case 3: foo() and foobar() public in p and t->foobar()

a) derived
b) output: derived (foo() is called from p::foobar() but still vtable of d is looked up and hence d::foo() is called)

Case 4: foo() is pvt in p and no foobar() in p and t->foo()

a) error (d::foo() is pvt) 
b) error (p::foo() is pvt)

*/
