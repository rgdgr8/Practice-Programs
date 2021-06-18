#include <iostream>
#include <vector>
using namespace std;

int max(vector<int>& s){
  return (s[(s.size()-1)]);
}

int mex(vector<int>& s){
  for(int i=0;i<s.size();i++)
     if(s[i]!=i)
       return i;
     
  return max(s)+1;
}

int main()
{
 int t;
 cin>>t;
 while(t-->0){
   int n,k;
   cin>>n;
   cin>>k;
   vector<int> s(n);
   for(int i=0;i<n;i++)
      cin>>s[i];
   
   sort(s.begin(),s.end());
   int c = n;

   while(k-->0){
     int mexs = mex(s);
     int maxs = max(s);
     int x = mexs+maxs;
     if(x%2!=0)
       x = (x+1)/2;
     else
       x = x/2;

     int flag = 0;
     for(int i=0;i<s.size();i++)
        if(x==s[i]){
          flag = 1;
          break;
        }
     if(flag==0){
        s.push_back(x);
        c++;
        sort(s.begin(),s.end());
     }else
        break;
   }
   cout<<c<<endl;
 }
}

