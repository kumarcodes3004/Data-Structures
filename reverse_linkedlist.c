#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;
 void display(){
     struct node* ptr;
     ptr= head;
     while(ptr!=NULL){
         printf("%d\n", ptr->data);
         ptr=ptr->next;
     }
     printf("\n");
 }

 void reverse_list(){
      struct node *prev, *cur;
      if(head!=NULL){
          prev= head;
          cur=head->next;
          head=head->next;
          prev->next=NULL;
      }
       while(head!=NULL){
           head=head->next;
           cur->next=prev;
           prev=cur;
           cur=head;
       }
       head=prev;
 }
 int getMiddle( struct node *head)
    {
        // if(head==NULL){
        //     return -1;
        // }else{
       int count =0;
		 struct node *temp=head;
		while(temp!=NULL){
		    count++;
		    temp=temp->next;
		}
 		 struct node *temp1=head;
		if(count%2==0){
		    for(int i=1;i<=(count/2)+1;i++){
		        temp1=temp1->next;
		    }
		    return temp1->data; 
		}else{
		    for(int i=1;i<=(count/2);count++){
		        temp1=temp1->next;
		    }
		    return temp1->data;
		}
    
    }
    // }
 

 int main(){
     head= (struct node*)malloc(sizeof(struct node));
     struct node * second= (struct node*)malloc(sizeof(struct node));
     struct node * third= (struct node*)malloc(sizeof(struct node));
     struct node * fourth= (struct node*)malloc(sizeof(struct node));
     head->data=1;
     head->next=second;
     
     second->data=2;
     second->next=third;
     third->data=3;
     third->next=fourth;
     fourth->data=4;
     fourth->next=NULL;
     display();
     getMiddle(head);
     reverse_list();
     display();
 
     return 0;


 }