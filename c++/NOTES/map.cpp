#include <iostream>
#include <string>
#include <map>
using namespace std;

class student{
   static int rolls;
   int roll;
   string name;
   public:
   //student():name(""),roll(0){cout<<"default"<<endl;};
   student(const string& name):name(name),roll(rolls){rolls++;/*cout<<"prog defined"<<endl;*/}
   friend ostream& operator<<(ostream& o,const student& s) {
      o<<s.roll<<" "<<s.name;
      return o;
   }
};
int student::rolls = 1;

int main()
{
 map<int,student,greater<int> > m;
 int x = 0;
 do{
   string name;
   cout<<"Enter name: ";
   getline(cin,name);
   cout<<"Enter score: ";
   cin>>x;
   m.insert(pair<int,student>(x,student(name)));

/************************************/
   //m[x] = student(name);//m[x] calls the default cst and student(name) calls the explicit cst,so the csts get called twice, this can get problematic. And also we cant use m[x] without a default cst
/**********************************/

   cout<<"Enter another? (yes=1,no=0) ";
   cin>>x;
   if(x!=0)
     cin.ignore();
 }while(x>0);

 for(map<int,student,greater<int> >::iterator it = m.begin();it!=m.end();it++)
    cout<<it->second<<" "<<it->first<<endl;
}

