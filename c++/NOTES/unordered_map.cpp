#include <iostream>
#include <utility>
#include <unordered_map>
#include <functional>
using namespace std;

class X{
  public:
  int a;
  char b;
  X(int a):a(a),b('c'){}
  bool operator==(const X& c) const {return a == c.a;}
  friend ostream& operator<<(ostream& o,const X& c) {o<<c.a<<" "<<c.b;return o;}
};


/*this class is the higlight of this program!!!!!!!!!!*/
class X_hash{
  public:
  //function pointer is not accepted in unordered_map template, only function object!****
  size_t operator()(const X& x) const {
     return hash<int>()(x.a);
  }
};
/******************************************************/


int main()
{
  unordered_map<X,int,X_hash> um;
  um.insert(pair<X,int>(X(1),11));
  um.insert(pair<X,int>(X(2),22));
  um.insert(pair<X,int>(X(3),33));
  unordered_map<X,int,X_hash>::iterator it = um.find(X(4));
  if(it!=um.end())
     cout<<it->first<<" "<<it->second<<endl;
  else
     cout<<"oal"<<endl<<endl;
   
  for(it=um.begin();it!=um.end();it++)
     cout<<it->first<<" "<<it->second<<endl;
}

