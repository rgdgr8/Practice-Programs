#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef struct data{//user defined data type for sorting vertices and distance between them
  int a;
  int b;
  int w;
}data;
int comp(data a, data b){//comparator for sorting according to distance between vertices
  return (a.w<b.w);
}

class node{//tree structure for implementing disjoint sets data structure
 public:
  int id;
  int height;
  node* parent;
  vector<node*> children;
  node(int id){
    this->id = id;
    parent = nullptr;
    height = 1;
  }
};
class disjoint_set{//disjoint set data structure
  private:
   vector<node*> nodes;
  public:
   disjoint_set(int vertices){
     for(int i=0;i<vertices;i++){
        node *n = new node(i);
        nodes.push_back(n);
     }
   }
   node* find_root(int id){
    node* x = nodes[id];
    while(x->parent!=nullptr)
         x = x->parent;
    return x;
   }
   void make_union(int a,int b){
    node* x = find_root(a);
    node* y = find_root(b);
    if(x==y)
      return;
    if(x->height>y->height){
       x->children.push_back(y);
       y->parent = x;
    }
    else if(y->height>x->height){
       y->children.push_back(x);
       x->parent = y;
    }
    else{
       x->children.push_back(y);
       y->parent = x;
       x->height++;
    }
   }
   int mst(vector<data> v){//function to calculate minimum spanning tree cost
    int tcost = 0;
    for(data d : v){
       if(find_root(d.a)!=find_root(d.b)){
         make_union(d.a,d.b);
         tcost+=d.w;
       }
      // cout<<d.a<<" "<<d.b<<" "<<d.w<<" tcost="<<tcost<<endl;
    }
    return tcost;
   }
};

void print_graph(vector<data> v,int vertices){//helper function to print all read input
  cout<<vertices<<endl;
  for(data d : v){
     cout<<d.a<<" "<<d.b<<" "<<d.w<<endl;
  }
}

int main()
{
  vector<data> graph;
  cout<<"Enter data file name: ";
  char* s = new char[100];
  cin>>s;
  ifstream input(s);
  delete []s;
  istream_iterator<int> it(input),eos;
  int vertices = *it;it++;
  while(it!=eos){
    data x;
    x.a = *it;it++;
    x.b = *it;it++; 
    x.w = *it;it++;
    graph.push_back(x);
  }
  sort(graph.begin(),graph.end(),comp);
  //print_graph(graph,vertices);
  disjoint_set ds(vertices);
  int cost = ds.mst(graph);
  cout<<cost<<endl;
  return 0;
}
