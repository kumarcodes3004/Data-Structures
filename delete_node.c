#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node* head;

void transversal(struct node *ptr){
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr= ptr->next;
    }
    
}
struct node *deleteithnode(struct node *head,int pos){
    
    if(pos==0){
       head=head->next;
        return head;
    }
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<pos-1;i++){
       p=p->next;
       q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;

}

int main(){
    
    struct node *second;
    struct node *third;
    struct node *fourth;
     head=(struct node*) malloc(sizeof (struct node));
     second= (struct node*) malloc(sizeof(struct node));
     third = (struct node*) malloc(sizeof(struct node));
     fourth = (struct node*) malloc(sizeof(struct node));
      head->data=1;
      head->next=second;
      second->data=2;
      second->next=third;
      third->data=3;
      third->next=fourth;
      fourth->data=4;
      fourth->next=NULL;
      transversal(head);
      head= deleteithnode(head,1);
      transversal(head);


}