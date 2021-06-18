#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int size = 50; //number of nodes
const long long max_val = 9999999999;
//------------ALL commented out function calls and prints were used for debugging--------
//------------function names are self descriptive------------
void print_graph(bool graph[size][size]);
void print_weights(vector<int> weights[]);
void print_edges(vector<int> edges[]);
void fill_graph(vector<int> weights[],vector<int> edges[]){
 srand(time(0));
 bool graph[size][size];
 bool filled[size][size] = {0};
 float density; int range;
 cout<<"Enter density and Range: ";
 cin>>density>>range;
 for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
       if(filled[i][j]==1)//checks to see if edge for (i,j) has already been made or not
          continue;

       if(i==j){
         graph[i][j]=0;
         filled[i][j]=1;
       }
       else{
//---------randomly make egdes between nodes--------------
         if(density>=0.5)//if density is greater than 0.5 one prob function is used
           graph[i][j] = graph[j][i] = ((rand()%200)*0.1/36)<density;
         else //if density lesser than 0.5 another prob function is used
           graph[i][j] = graph[j][i] = ((rand()%200)*0.1/36)>density;
         filled[i][j] = filled[j][i] = 1;
	 if(graph[i][j]==1){//adding random weights to edges
           int x = (rand()%range)+1;
           weights[i].push_back(x);
           weights[j].push_back(x);
           edges[i].push_back(j);
           edges[j].push_back(i);
         }
       }
    }
 }
  //print_graph(graph);
}

void print_arr(long long arr[]);
int curr_size = size;
long long shorts[size];//used for storing all minimum distances

int min_index(long long x[]){
 long long min = max_val+1;
 int ind = -1;
 for(int i=0;i<size;i++){
    if(x[i]!=-1 && x[i]<min){
      min = x[i];
      ind = i;
    }
 }

// cout<<"min val="<<min<<"min ind="<<ind<<endl;

 shorts[ind] = x[ind];
 x[ind] = -1;
 curr_size--;
 
 //print_arr(x);
 //print_arr(shorts);

 return ind;
}

void print_arr(long long arr[]){
 for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
 cout<<endl;
}

 double shortest_paths_avg(vector<int> weights[], vector<int> edges[]){
 long long dists[size];//to store all intermediate distance values of nodes
 for(int i=0;i<size;i++)
    dists[i] = max_val;
 dists[0] = 0;//starting node distance is obviously 0 from itself

 //print_arr(dists);
 //cout<<endl;

 while(curr_size>0){
  int ind = min_index(dists);
  for(int i=0;i<edges[ind].size();i++){
     int to = edges[ind].at(i);
     long long x = shorts[ind] + weights[ind].at(i);
     if(dists[to] > x)//if current distance of a node from start is greater than the current shortest node distance plus                       //the edge weight between these two nodes then change/decrease the value of node
       dists[to] = x;
  }
  //print_arr(dists);
  //cout<<endl;
 }

 //print_arr(shorts);

 long long shortests = 0;
 for(int i=0;i<size;i++){
    shortests+=shorts[i];
    shorts[i] = 0;
 }
 curr_size = size;
 double avg = ((double)shortests)/(size-1);//average of all the shortest distances from start
 return avg;
}

int main()
{
 int num;
 cout<<"How many graphs do you want to test?: ";
 cin>>num;
 while(num-->0){
   double avg = 0.0;
   vector<int> weights[size];
   vector<int> edges[size];
   fill_graph(weights,edges);
   avg = shortest_paths_avg(weights,edges);
   //print_edges(edges);
   //print_weights(weights);
   cout<<"Average Shortest Distance is "<<avg<<" units"<<endl;
 }
 return 0;
}

void print_edges(vector<int> edges[]){
 cout<<"Edges:"<<endl;
 for(int i=0;i<size;i++){
    cout<<i<<"| ";
    for(int j=0;j<edges[i].size();j++)
       cout<<edges[i].at(j)<<" ";
    cout<<endl;
 }
 cout<<endl;
}
void print_graph(bool graph[size][size]){
 cout<<"   ";
 for(int i=0;i<size;i++)
    cout<<i<<" ";
 cout<<endl<<"   ";
 for(int i=0;i<size;i++)
    cout<<"- ";
 cout<<endl;
 for(int i=0;i<size;i++){
    cout<<i<<"| ";
    for(int j=0;j<size;j++)
       cout<<graph[i][j]<<" ";
    cout<<endl;
 }
 cout<<endl;
}
void print_weights(vector<int> weights[]){
 cout<<"Weights:"<<endl;
 for(int i=0;i<size;i++){
    cout<<i<<": ";
    for(int j=0;j<weights[i].size();j++)
       cout<<weights[i].at(j)<<" ";
    cout<<endl;
 }
}
