#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
   struct node *left;
    struct node *right;
    int data;
};
 

   
struct node *createtree(){
    int val;
 
   struct node *root =NULL;
    root=(struct node*)malloc(sizeof(struct node));
   
    printf("give data: ");
    scanf("%d", &val);
    if(val==-1){
         return NULL;
    }else{
        root->data=val;
        printf("enter left for %d",val);
        root->left= createtree();

        printf("enter the right for %d",val);
        root->right=createtree();
        
    }
    return root;
}

//////
int height(struct node *root){
    if(root==NULL) {
        return 0;
    }else{
        return fmax(height(root->left),height(root->right))+1;
    }
}
int size(struct node *root){
    if(root==NULL){
        return 0;
    }else{
        return size(root->left)+size(root->right)+1;
    }
}

int maximum(struct node *root){
    if(root==NULL){
        return INT_MIN;
    }else{
        return fmax(root->data,fmax(maximum(root->left),maximum(root->right)));
    }
}


void inorder(struct node* root){
    if(root==NULL)   return;
      
    
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        
    
}

void postorder(struct node* root){
    if(root==NULL)   return;
      
    
        postorder(root->left);
        
        postorder(root->right);
    printf("%d ",root->data);
     
}
void preorder(struct node* root){
    if(root==NULL)   return;
      
    printf("%d ",root->data);
        preorder(root->left);
        
        preorder(root->right);
    
}
int main(){
  struct node *root1= (struct node*)malloc(sizeof(struct node));
     root1=createtree();
     int x= height(root1);
     printf("height is %d\n", x);
     int y=size(root1);
     printf("size is: %d\n", y);
     int z = maximum(root1);
     printf("maximum in binarty tree is  %d\n", z);
    inorder(root1);
     printf("\n");
    preorder(root1);
     printf("\n");
    postorder(root1);
     printf("\n");
}
