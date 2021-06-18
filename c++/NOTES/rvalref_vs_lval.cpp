#include <iostream>
#include <vector>
#include <string>
using namespace std;

ostream& operator<<(ostream& o,vector<int>& v){
   for(int i=0;i<v.size();i++)
      cout<<v[i]<<" ";
   return o;
}

int main(){
 vector<int> x{1,2,3};
 cout<<x.data()<<endl;
 vector<int>&& y = move(x);
 //vector<int> y = move(x);         //SEE THE DIFFERENCE.
 cout<<y.data()<<endl<<endl;
 cout<<x.data()<<endl;
 cout<<x<<endl;
 cout<<y<<endl;
 cout<<y.data()<<endl;
 return 0;
}

/* THIS HAPPENS AS && IS A REFRENCE TO AN MEMORY ADDR, SO IT ACTS JUST LIKE A LVALUE REFERENCE WHEN 
   =move IS USED ON IT. WHILE A LVALUE y=move(x) HAS A MOVE CONSTRUCTOR DEFINED WHICH NULLS THE VALUE OF
   x. */
