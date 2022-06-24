#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    };
   struct node *head;

   void insert_beg(){
       int val;
       struct node *new_node,*ptr;
       new_node=(struct node*)malloc(sizeof(struct node));
       if(new_node==NULL){
           printf("\nOVERFLOW\n");
       }else{
           printf("give elemnet: ");
           scanf("%d", &val);
           new_node->data=val;
           if(head==NULL){
               new_node->next=new_node;
               head=new_node;
           }else{
               ptr=head;
               while(ptr->next!=NULL){
                   ptr=ptr->next;
               }
               ptr->next=new_node;
               new_node->next=head;
               head=new_node;
           }
       }
   }

   void insert_end(){
       int val;
       struct node *ptr,*new_node;
       new_node=(struct node*)malloc(sizeof(struct node));
       if(new_node==NULL){
           printf("OVERFLOW\n");
       }else{
           printf("give elemnt: ");
           scanf("%d", &val);
           ptr=head;
           while(ptr->next!=head){
               ptr=ptr->next;
           }
            ptr->next=new_node;
            new_node->next=head;

       }
   }

   void display(){
       struct node *ptr;
       ptr=head;
       while(ptr->next!=head){
           printf("%d\t", ptr->data);
           ptr=ptr->next;
       }
       printf("%d",ptr->data);
       printf("\n");
   }

   int main(){
       int choice;
       head=(struct node*)malloc(sizeof(struct node));
       while(1>0){
           printf("WELCOME TO CLL\n");
           printf("1.insert beg\n2.insert end\n3.dispaly\n4.end\n");
           printf("give ur choice: ");
           scanf("%d", &choice);
            switch (choice)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
           display();
            break;
        case 4:
            printf("\nTHE END\n");
            exit(0);
        default:
            printf("NOT VALID\n");
        }
    }
    return 0;
       }
   