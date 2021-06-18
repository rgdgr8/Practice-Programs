#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <fstream> 
#include <iterator> 
using namespace std;
 
void print_state (fstream& stream) {
  cout << " good()=" << stream.good();
  cout << " eof()=" << stream.eof();
  cout << " fail()=" << stream.fail();
  cout << " bad()=" << stream.bad();
}
int main() 
{ 
 fstream f;f.open("data.txt", ios::out);//to create a file  if not exists
 f<<"1 2 3 4 5"<<endl;f.close();

 fstream file("data.txt",ios::out|ios::in);
 cout<<"Begin: "<<file.rdstate()<<"\t";print_state(file);cout<<endl;

 istream_iterator<int> cin_it(file); //single pass iterator
 istream_iterator<int> eos; 
 ostream_iterator<int> cout_it(cout," ");  //single pass iterator

 copy(cin_it, eos, cout_it);cout<<endl<<endl;//iterator gets used, cant be passed anymore.
 cout<<"After first copy: "<<file.rdstate()<<"\t";print_state(file);cout<<endl;

 file.clear();//VERY IMPORTANT. THIS RESETS ALL THE INTERNAL FLAGS, SO THE FILE CAN BE READ AGAIN
 cout<<"After clear: "<<file.rdstate()<<"\t";print_state(file);cout<<endl;

 file.seekg(0, ios::beg);//USING THIS WITHOUT ios::clear may NOT work.
 cout<<"After seek: "<<file.rdstate()<<"\t";print_state(file);cout<<endl;

 istream_iterator<int> cin_it2(file); //this iterator will be unable to read file without the above two statements!!!!!!!!
 istream_iterator<int> eos2; 

 vector<int> x(cin_it2,eos2);
 //copy(x.begin(), x.end(), cout_it);cout<<endl<<endl;
 for(auto i=x.begin();i!=x.end();++i)
 //for(auto i=cin_it;i!=eos;++i)
    cout<<*i<<" ";
 cout<<endl;
 cout<<"End: "<<file.rdstate()<<"\t";print_state(file);cout<<endl;

 return 0; 
} 
