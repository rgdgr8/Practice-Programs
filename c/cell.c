#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *cells,*visited;
int n,t;
void explore(int index, int a){
 if(index==t){
   printf("YES");
   return;
 }
 if(index==n && t!=n){
   printf("NO");
   return;
 }
 visited[index-1] = 1;
 if(visited[index-1+a]==0)
   explore((index+a),cells[index-1+a]);
}
int main()
{ 
 scanf("%d %d",&n,&t);
 cells = malloc(n*sizeof(int));
 visited = malloc(n*sizeof(int));
 for(int i=0;i<n-1;i++){
    scanf("%d",&cells[i]);
    visited[i] = 0;
 }
 visited[n-1] = 0;
 explore(1,cells[0]);
 return 0;
}
