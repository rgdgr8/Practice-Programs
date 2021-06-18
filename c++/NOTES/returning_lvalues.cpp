#include <iostream>
using namespace std;

int a = 3;
int& getRef () 
{
 int &x = a;
 return x;
}

int* getPtr ()
{
 int *x = &a;
 return x;
}

int main()
{
 getRef() = 5;//works because return reference may be temporary but it's referring to a permanent address
 cout<<a<<endl;
 //getPtr() = new int(5); does not work as pointer returned is temp but.....
 *(getPtr()) = 9;//works because, though returned ptr is temp but the address it's pointing to is permanent
 cout<<a<<endl;
 return 0;
}
