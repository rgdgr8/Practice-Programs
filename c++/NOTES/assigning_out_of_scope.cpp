#include<iostream>

struct foo
{
  int a;
};

foo q() { foo f; f.a =4; return f;}

int main()
{
  foo i;
  i.a = 5;
  q() = i;//works because of operator= overloading as explained in the para below.
//see bookmark "Assignig out of scope" if needed.
}
/*
************If the type returned were a BASIC/PRIMITIVE type then this would be a compile error. --------*************

The reason that this works is that you are allowed to call member functions (even non-const member functions) on r-values of class type and the assignment of foo is an implementation defined member function: foo& foo::operator=(const foo&). The restrictions for operators in clause 5 only apply to built-in operators, if overload resolution selects an overloaded function call for an operator then the restrictions for that function call apply instead.

This is why it is sometimes recommended to return objects of class type as const objects (e.g. const foo q();), however this can have a negative impact in C++0x where it can inhibit move semantics from working as they should.

*/
