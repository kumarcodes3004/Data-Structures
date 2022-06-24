#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node reverse( struct node *head){
   struct node *curr = head;
    struct node *prev= NULL;
    while (curr!=NULL)
    {
      struct node *temp= curr->next;
       curr->next=prev;
       prev=curr;
       curr=temp;
    }
    return *prev;
}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->data= 7;
    head->next=second;

    second->data=9;
    second->next=third;

    third->data=29;
    third->next=NULL;   
    printf("%d\n", head->data);
    printf("%d\n", second->data);
    printf("%d\n", third->data);
    reverse(head);
    printf("%d\n", head->data);
    printf("%d\n", second->data);
    printf("%d\n", third->data);



    // while ()
    // {
    //     /* code */
    // }
    
}