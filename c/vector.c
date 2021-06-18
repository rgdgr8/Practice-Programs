#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point{int x,y,z;}point;

/*float dist(point a){
 float dist = sqrt(a.x*a.x +a.y*a.y +a.z*a.z);
 return dist;
}*/

int main()
{
 int n;
 scanf("%d",&n);
 point coords[n];
 int sumx = 0;
 int sumy = 0;
 int sumz = 0;  
 for(int i=0;i<n;i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    coords[i].x = x;
    coords[i].y = y;
    coords[i].z = z;
    sumx += x;
    sumy += y;
    sumz += z;
 }
 if(sumx==0 && sumy==0 && sumz==0)
   printf("YES");
 else
   printf("NO");
 return 0;
}
