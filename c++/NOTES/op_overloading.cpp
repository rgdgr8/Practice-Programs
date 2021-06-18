#include <iostream>
using namespace std;

typedef enum days{sun,mon,tue,wed,thur,fri,sat}days;

inline days operator++(days d){
  return static_cast<days>((static_cast<int>(d)+1)%7);
}

ostream& operator<<(ostream& out, const days &d){
  switch(d){
    case sun: out<<"Sunday!"<<endl;break;
    case mon: out<<"Monday :-("<<endl;break;
    case tue: out<<"Tuesday :-("<<endl;break;
    case wed: out<<"Wednesday :-("<<endl;break;
    case thur: out<<"Thursday :-("<<endl;break;
    case fri: out<<"Friday :~("<<endl;break;
    case sat: out<<"Saturday :-)"<<endl;break;
    default : out<<"WTF???"<<endl;
  }
  return out;
}

int main()
{
 days a = sat;
 cout<<a;
 days b = ++a;
 cout<<b;
 return 0;
}

