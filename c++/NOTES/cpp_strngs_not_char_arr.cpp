#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Method for strings and not char arr, since strings can expand but we need char arr in case 
  we want only the first n number of chars and not the whole thing*/

int main()
{
 int n;
while(true){
 cout<<"Enter a number\n";
 cin>>n;
 cin.ignore();//!!!!!!!!
 string s;
 getline(cin,s);
 cout<<s<<endl;
}
 return 0;
}

