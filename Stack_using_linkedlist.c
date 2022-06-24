#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
// int top = -1;
struct node* top;

void display(){
    struct node* ptr;
    ptr=top;
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
}

// int isempty(){
    
//     if(top==NULL){
//         return 1;
//     }else{
//         return 0;
//     }
// }

//  int isfull(){
//     struct node* p= (struct node*)malloc(sizeof(struct node));
//     if(p==NULL){
//         return 1;
//     }else{
//         return 0;
//     }
// }

void push(){
     struct node* p= (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
    printf("stackoverflow\n");
    }else{
        // struct node* p= (struct node*)malloc(sizeof(struct node));
        int val;
        printf("give the element:");
        scanf("%d", &val);
        p->data=val;
        p->next=top;
        top=p;

    }
}

void pop(){
    if(top==NULL){
        printf("stackunderflown\n");
    }else{
        struct node* n= top;
         int x= n->data;
   
        top= top->next;
       
        free(n);
        printf("the element popped is: %d\n", x);
    }
}

int main(){

printf("WELCOME TO STACK USING LL\n");
int key;

while(1>0){
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &key);
        if(key==1){
            push();
        }else if(key==2){
            pop();
        }else if(key==3){
            display();
        }else{
            printf("END OF THE PROGRAMME");
            break;
        }
    }
    return 0;
}