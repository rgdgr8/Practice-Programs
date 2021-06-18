#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define max(a,b) (a)<=(b) ? (b) : (a)

typedef struct avl_node{
  int v;
  struct avl_node* left;
  struct avl_node* right;
  struct avl_node* parent;
  int height;
}node;

int inp[] = {1,2,3,4,5,6,8,9,10,7,11};
int in = 0;
void initiate(node* x){
  x->left = NULL;
  x->right = NULL;
  x->parent = NULL;
  x->height = 1;
  int v = inp[in++];
  //printf("Enter a value: ");
  //scanf("%d",&v);
  x->v = v;
}

void in_order_print(node* root){
  if(!root)
    return;

  in_order_print(root->left);
  printf("v=%d  h=%d",root->v,root->height);
  if(root->left)
    printf("  l=%d",root->left->v);
  else
    printf("  l=NULL");
  if(root->right)
    printf("  r=%d",root->right->v);
  else
    printf("  r=NULL");
  printf("\n");
  in_order_print(root->right);
}

node* find(int v,node* root){//if found return the correct node, else returns the position where the node should be.
   node* cur = root;
   node* prev = NULL;
   while(cur){
     prev = cur;
     if(cur->v==v)
        return cur;
     else if(cur->v<v)
        cur = cur->right;
     else
        cur = cur->left;
   }
   return prev;
}

node* next(node* x){//find the node with the next greater value than node x
   if(x->right){
     node* cur = x->right;
     while(cur->left)
          cur = cur->left;
     return cur;
   }

   node* cur = x->parent;
   while(cur && x->v > cur->v)
        cur = cur->parent;
   if(cur)
     return cur;

   return x;//x is the biggest element in the tree
}
void adjust_height(node*);
void add_child(node* c,node* p){
  //printf("add child child=%d  parent=%d\n",c->v,p->v);
  if(c->v > p->v)p->right = c;
  else p->left = c;
  adjust_height(p);
}
//avl methods from here on

void adjust_height(node *n){
   int left_height = 0,right_height = 0;
   if(n->left)left_height = n->left->height;
   if(n->right)right_height = n->right->height;
   int max = max(left_height,right_height);
   n->height = 1+max;
   //printf("max=%d  ",max);printf("Adjust v=%d  h=%d\n",n->v,n->height);
}

node *root = NULL;

void rotate_left(node *n){
   node* gp = n->parent;
   node* rc = n->right;
   node* rclc = rc->left;
   /*printf("rotate left\n");
   printf("n=%d  rc=%d",n->v,rc->v);
   if(gp)
     printf("  gp=%d",gp->v);
   else
     printf("  gp=NULL");
   if(rclc)
     printf("  rclc=%d",rclc->v);
   else
     printf("  rclc=NULL");
   printf("\n");*/

   if(gp){
     add_child(rc,gp);//add right child(rc) to parent of n
   }else{
    root = rc;
   }

   rc->parent = gp;
   rc->left = n;
   n->parent = rc;
   n->right = NULL;
   if(rclc){//if right child's left child exists
     n->right = rclc;
     rclc->parent = n;
   }
}

void rotate_right(node *n){
   node* gp = n->parent;
   node* lc = n->left;
   node* lcrc = lc->right;
 
   if(gp){
     add_child(lc,gp);//add left child(lc) to parent of n
   }else{
     root = lc;
   }

   lc->parent = gp;
   lc->right = n;
   n->parent = lc;
   n->left = NULL;
   if(lcrc){//if left child's right child exists
     n->left = lcrc;
     lcrc->parent = n;
   }
}

void reduce_left(node* n){
   int left_height = 0,right_height = 0;
   if(n->left->left)left_height = n->left->left->height;
   if(n->left->right)right_height = n->left->right->height;
   
   if(left_height<right_height)//double rotation required
     rotate_left(n->left);
   rotate_right(n);

//Adjusting the heights of the affected nodes, we can find them by trial and error
   adjust_height(n);
   if(n->parent->left)
     adjust_height(n->parent->left);
   adjust_height(n->parent);
}

void reduce_right(node* n){
   int left_height = 0,right_height = 0;
   if(n->right->left)left_height = n->right->left->height;
   if(n->right->right)right_height = n->right->right->height;
   
   if(left_height>right_height)//double rotation required
     rotate_right(n->right);
   rotate_left(n);

//Adjusting the heights of the affected nodes, we can find them by trial and error
   adjust_height(n);
   if(n->parent->right)
     adjust_height(n->parent->right);
   adjust_height(n->parent);
}

//int k = 0;
void balance(node* n,char* s){
   //k++;
   node* p = n->parent;
  /*if(strcmp(s,"ola")==0){
   printf("Balance n=%d  n->h=%d\n",n->v,n->height);
  if(p)
   printf("parent(p)=%d  p->h=%d\n",p->v,p->height);
  else
   printf("p is null\n");
  }*/
   int left_height = 0,right_height = 0;
   if(n->left)left_height = n->left->height;
   if(n->right)right_height = n->right->height;

   if(left_height > right_height+1)
     reduce_left(n);
   if(right_height > left_height+1)
     reduce_right(n);

   adjust_height(n);//needed for readjusting the heights of those parents who are not rotated.

   //printf("Adjusted n=%d  n->h=%d\n",n->v,n->height);
   //if(k>20)exit(0);
   if(p)
     balance(p,"");
}

void insert(node* root){
   node *n =  malloc(sizeof(node));
   initiate(n);

   node *x = find(n->v,root);
   assert(x!=NULL);
   if(x->v==n->v){//if node with given value already exists
     free(n);
     return;
   }
   n->parent = x;
   n->left = NULL;
   n->right = NULL;
   n->height = 1;
   add_child(n,x);
   
   balance(n,"");
}

void delete_node(int v,node* root){
   node *n = find(v,root);
   if(n->v != v)//if the given node does the not exist
     return;
 
   if(!n->right){//if n has no right child just promot left child
     if(!n->left){
       if(n->parent){
         if(n->parent->v < n->v)
           n->parent->right = NULL;
         else
           n->parent->left = NULL;
       }
       free(n); 
       return;
     }
     if(n->parent){
       add_child(n->left,n->parent);
       n->left->parent = n->parent;
     }else
       n->left->parent = NULL;
     balance(n->left,"");
     free(n);
   }else{
     node *r = next(n);//node to replace x with
     if(r==n){//if r is the largest(right most) element in tree then we can simply free it
       if(r->parent)
         r->parent->right = NULL;
       free(r);
       return;
     }
     //printf("%d\n",r->v);
     n->v = r->v;
     if(r->right && r->parent){
       add_child(r->right,r->parent);
       r->right->parent = r->parent;
       balance(r->right,"ola");
     }else if(r->parent->v==n->v){//if r is the direct right child of n
       if(r->right){
         n->right = r->right;
         r->right->parent = n;
       }else
         n->right = NULL;
       balance(n,"");
      }
      else if(!r->right && r->parent){
       r->parent->left = NULL;
       balance(r->parent,"");
      }
     free(r);
   }
}

int main()
{ 
  int del[] = {4,8,6};

  root = malloc(sizeof(node));
  initiate(root);
  while(in<11){
   insert(root);
   //k = 0;
  }
  in_order_print(root);//printf("\n");
  printf("--------------------------\n");
  in = 0;
  while(in<3){
   int x = del[in++];
   delete_node(x,root);
  }
  in_order_print(root);//printf("\n");
}
