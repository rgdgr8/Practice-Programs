#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class node{//tree structure for implementing disjoint sets data structure
 public:
  int id;
  int height;
  node* parent;
  node(int id){
    this->id = id;
    parent = nullptr;
    height = 1;
  }
};
 
class disjoint_set{//disjoint set data structure
  private:
   vector<node*> nodes;
   int vertices;
  public:
   disjoint_set(int vertices){
     this->vertices = vertices;
     for(int i=0;i<vertices;i++){
        node *n = new node(i);
        nodes.push_back(n);
     }
   }
   disjoint_set(const disjoint_set& ds):disjoint_set(ds.nodes.size()){
      for(int j=0;j<vertices;j++){
         nodes[j]->height = ds.nodes[j]->height;
         if(ds.nodes[j]->parent!=nullptr)
           nodes[j]->parent = nodes[ds.nodes[j]->parent->id];
      }
   }
   node* find_root(int id,int test=0){
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
       y->parent = x;
    }
    else if(y->height>x->height){
       x->parent = y;
    }
    else{
       y->parent = x;
       x->height++;
    }
   }
};

typedef struct move{
  int i;
  int j;
}move;

const char hex_pos = 'O';//hex box shape
const char hex_red = 'R';//red occuppied square
const char hex_blue = 'B';//blue occuppied square
class hex_game{
  private:
  enum Color{red,blue,white};
  struct check{
    bool visited;
    Color color;
  };
  check* pos;
  int size;
  int **conns;
  int vertices;
  disjoint_set* ds;
  int player;
  int curr_vertices;

 void comp_move(){
  int gm[vertices];
  int tries[vertices];
  for(int i=0;i<vertices;i++){
     gm[i] = 0;
     tries[i] = 0;
  }
  Color comp_c = static_cast<Color>(!player);
  for(int i=0;i<3000;i++){//3000 trials
   int cv = curr_vertices;
   int first = -1;
   int x,moves = 0;
   check tpos[vertices];//trial position
   disjoint_set *tds = new disjoint_set((*ds));//trial disjoint set
   for(int i=0;i<vertices;i++)
      tpos[i] = pos[i];
   Color c = static_cast<Color>(!player); 
   string res = "Game is on";
   while(res=="Game is on"){//do until one trial game has ended
    do{//randomly generate positions until legal move
      x = rand()%vertices;
    }while(tpos[x].visited==true);
    moves++;
    cv--;
    //cout<<"x="<<x<<" cv="<<cv<<" color="<<c<<endl;
    tpos[x].visited = true;
    tpos[x].color = c;
    if(first==-1 && c==comp_c){
      first = x;
      tries[x]++;//number of trials with a particular move
    }
    for(int i=1;i<7;i++){//make union if any adjacent hex is present
     if(conns[x][i]!=-1)
       if(tpos[conns[x][i]].visited && tpos[conns[x][i]].color==c)
         tds->make_union(x,conns[x][i]);
    }
    if(c==red)c=blue;else c=red; 
    if((cv>3*size && moves==size) || (cv<=3*size)){//check result periodically
      res = result(tpos,tds);
      if(res!="Game is on" && ((comp_c==blue && res=="Blue has Won!") || (comp_c==red && res=="Red has Won!")))
         gm[first]++;//number of wins with a particular move
      moves = 0;
    }
   }
   delete tds;
  }
  //cout<<"out of loop"<<endl;
  double bm[vertices];//ratio of wins/trials
  for(int i=0;i<vertices;i++){
      bm[i]=-1;
      if(tries[i]>0)
         bm[i] = (static_cast<double>(gm[i]))/tries[i]; 
  }
  int max_i = -1;
  double max = -1.0;
  for(int i=0;i<vertices;i++){
     if(max<bm[i]){
       max_i = i;
       max = bm[i];
     }
  }
  pos[max_i].visited = true;
  pos[max_i].color = comp_c;
  make_union(max_i);
  draw_board();
 }

 void make_union(const int& max_i){
  for(int i=1;i<7;i++){//make union if any adjacent hex is present
     if(conns[max_i][i]!=-1)
       if(pos[conns[max_i][i]].visited && pos[conns[max_i][i]].color==pos[max_i].color)
         ds->make_union(max_i,conns[max_i][i]);
  }
 }

  void player_move(){
   string l;
   struct move m;
    do{
     cout<<"Enter a move as i,j or as i j (0 indexing): ";
     cin>>m.i;
     char c = getchar();
     if(c>=48 && c<=57)
      m.j = c-48;
     else
      cin>>m.j;
     l = legal(m);
    }while(l=="Illegal Move");
    int x = m.i*size+m.j;
    pos[x].visited = true;
    pos[x].color = static_cast<Color>(player);
    make_union(x);
    //draw_board();
  }

  string result(check *pos,disjoint_set* ds){
     vector<int> findsNorth;
     vector<int> findsSouth;
     for(int i=0;i<size;i++){
        if(pos[i].visited && pos[i].color==red){
          findsNorth.push_back(ds->find_root(i)->id);
        }
     }
     for(int i=(vertices-size);i<vertices;i++){
        if(pos[i].visited && pos[i].color==red){
          findsSouth.push_back(ds->find_root(i)->id);
        }
     }
     for(int i=0;i<findsNorth.size();i++){
        for(int j=0;j<findsSouth.size();j++){
           if(findsNorth[i]==findsSouth[j]){
             return "Red has Won!";
           }
        }
     }
     //cout<<"Red check done"<<endl;
     vector<int> findsWest;
     vector<int> findsEast;
     for(int i=0;i<=vertices-size;i+=size){
        if(pos[i].visited && pos[i].color==blue){
          findsWest.push_back(ds->find_root(i)->id);
        }
     }
     for(int i=size-1;i<vertices;i+=size){
        if(pos[i].visited && pos[i].color==blue){
          int z = ds->find_root(i)->id;
          //cout<<z<<endl;
          findsEast.push_back(z);
        }
     }
     for(int i=0;i<findsWest.size();i++){
        for(int j=0;j<findsEast.size();j++){
           if(findsWest[i]==findsEast[j])
             return "Blue has Won!";
        }
     }
     //cout<<"Blue check done"<<endl;
     return "Game is on";
  }

  void draw_board(){//drawing the board
    cout<<"      ";
    for(int i=0;i<size;i++)
        cout<<i<<"   ";
    cout<<endl;
    for(int i=0;i<size;i++){
      cout<<i<<"     ";
      for(int j=0;j<size;j++){
         int x = i*size+j;
        if(pos[x].visited==true)
         switch(pos[x].color){
           case red: cout<<hex_red;break;
           case blue: cout<<hex_blue;break;
           default: cout<<hex_pos;
         }
        else
         cout<<hex_pos;
         if(j!=size-1){
           cout<<" - ";
         }
      }
      cout<<endl;
      cout<<"     ";
      if(i!=size-1){
        for(int k=0;k<=i;k++)
           cout<<" ";
        for(int j=0;j<size;j++){
           cout<<"\\ ";
           if(j!=size-1)
             cout<<"/ ";
        }
      }
      cout<<endl;
      for(int k=0;k<=i;k++)
         cout<<" ";
    }
  }

  void fill(){
    for(int i=0;i<vertices;i++){
       pos[i].visited = false;//hex_position unoccupied
       pos[i].color = white;
       if((i+1)%size==0 || i%size==0 || i<size || i>=(vertices-size))
          conns[i][0] = 4;//number of edges
       else
          conns[i][0] = 6;//number of edges
    }

   //corner cases
    conns[0][0] = 2;
    conns[vertices-1][0] = 2;
    conns[vertices-size][0] = 3;
    conns[size-1][0] = 3;
    
    for(int i=0;i<vertices;i++){//storing edges position
       conns[i][1] = i+1;
       conns[i][2] = i-1;
       conns[i][3] = i-size;
       conns[i][4] = i-size+1;
       conns[i][5] = i+size;
       conns[i][6] = i+size-1;
       if((i+1)%size==0){
          conns[i][4] = -1;
          conns[i][1] = -1;
       }else if(i%size==0){
          conns[i][2] = -1;
          conns[i][6] = -1;
       }else if(i<size){
          conns[i][3] = conns[i][4] = -1;
       }else if(i>=(vertices-size)){
          conns[i][5] = conns[i][6] = -1;
       }
    }

   //corner cases
    conns[0][2] = conns[0][3] = conns[0][4] = conns[0][6] = -1;
    conns[vertices-1][1] = conns[vertices-1][4] = conns[vertices-1][5] = conns[vertices-1][6] = -1;
    conns[vertices-size][2] = conns[vertices-size][5] = conns[vertices-size][6] = -1;
    conns[size-1][1] = conns[size-1][3] = conns[size-1][4] = -1;
  }

  public:
  string legal(struct move m){
   int ind = m.i*size+m.j;
   if(ind<(size*size) && !pos[ind].visited)
      return "Legal Move";
   return "Illegal Move"; 
  }

  hex_game(int size,int player){
    this->size = size;
    vertices = size*size;
    pos = new check[vertices];//hex positions stored in 1D instead of 2D
    conns = new int*[vertices];
    curr_vertices = vertices;
    for(int i=0;i<vertices;i++){
       conns[i] = new int[7];
    }
    if(player==0)
      draw_board();
    fill();
    this->player = player;
    ds = new disjoint_set(vertices);
    srand(time(0));
  }
  
void play(){
 int moves = 0;
 string res = "Game is on";
 while(res=="Game is on"){//till actually game ends
   if(player==red){
     player_move();
     comp_move();
   }else{
     comp_move();
     player_move();
   }
   curr_vertices-=2;
   res = result(pos,ds);//check result regularly
   /*moves+=2;
   if((curr_vertices>3*size && moves==size) || curr_vertices<=3*size){//check result periodically
     moves=0;
     res = result(pos,ds);
   }*/
 }
 cout<<endl<<res<<endl;
}

  ~hex_game(){delete []pos;for(int i=0;i<vertices;i++)delete []conns[i];delete []conns;delete ds;}   
};

int main()
{
 int size;
 int color;
 cout<<"Board size?: ";
 cin>>size;
 cout<<"Choose color: (Red=0,Blue=1): ";
 cin>>color;
 hex_game game(size,color);
 game.play();
 return 0;
}

