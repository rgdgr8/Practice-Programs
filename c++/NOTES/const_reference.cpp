#include <iostream>
using namespace std;

int main()
{
 int a = 9;
 const double &b = a;//try without const keyword!
 a = 11;//changes a not b!
 cout<<a<<endl;
 cout<<&a<<endl;
 cout<<b<<endl;
 cout<<&b<<endl;
 return 0;
}

