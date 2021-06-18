#include <iostream>
#include <fstream>
using namespace std;

int main()
{
 fstream f("x.dat",ios::out);f.close();
 int x = 9;
 f.open("x.dat",ios::in|ios::out);
 if(!f)
    cout<<"failed"<<endl;
 
 f.write((char*)&x,sizeof(int));
 x += 90;
 f.write((char*)&x,sizeof(int));
 x += 900;
 f.write((char*)&x,sizeof(int));
 x += 9000;
 f.close();
 
 f.open("x.dat",ios::in|ios::out);
 if(!f)
    cout<<"failed2"<<endl;
 
 f.seekp(0,ios::end);
 f.write((char*)&x,sizeof(int));//write pointer has reached set all flags read pointer hasn't so we needn't do f.clear() hear.
 
 f.seekg(0,ios::beg); 
 f.read((char*)&x,sizeof(int));
 while(!f.eof()){
      cout<<x<<endl;
      f.read((char*)&x,sizeof(int));
 }

 f.clear();//but here f.clear() is a must, since read pointer also has set all flags.
 f.seekg(0,ios::beg); 
 f.read((char*)&x,sizeof(int));
 while(!f.eof()){
      cout<<x<<endl;
      f.read((char*)&x,sizeof(int));
 }
}

