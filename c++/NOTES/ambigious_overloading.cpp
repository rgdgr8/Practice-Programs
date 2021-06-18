#include<iostream>
#include<cstdlib>
using namespace std;
void x(int a){
  cout<<"One arg func\n";
}
void x(int a,int b=0){//if second argument is defaulted then call becomes ambigious, try remove "=0" and call x again
 cout<<"Two arg func\n";
}
int main()
{
 x(1);
 return 0;
}
