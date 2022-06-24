#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    };

    struct node *front, *rear;

    void enqueue(){
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        int item;
        if(ptr==NULL){
            printf("overflown\n");
        }else{
            printf("enter the value:-");
            scanf("%d", &item);
            ptr->data=item;
            if(front==NULL){
                front=ptr;
                rear=ptr;
                front->next=NULL;
                rear->next=NULL;
            }else{
                rear->next=ptr;
                rear=ptr;
                rear->next=NULL;
            }
        }
    
    }
    void dequeue(){
        struct node *ptr;
        if(front==NULL){
        printf("underflown\n");
    }else{
        ptr=front;
        printf("element removed is :%d\n", ptr->data);
        front= front->next;
        free(ptr);
    }
    }

    void display(){
        struct node* ptr;
        ptr=front;
        if(front==NULL){
             printf("underflown\n");
        }else{
            while(ptr!=NULL){
                printf("%d\n", ptr->data);
                ptr=ptr->next;
            }
        }
    }
    int main(){
        int key;
        printf("WELCOME TO QUEUE'S USING LL\n");
        while(1>0){
            printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &key);
        if(key==1){
            enqueue();
        }else if(key==2){
            dequeue();
        }else if(key==3){
            display();
        }else{
            printf("END OF THE PROGRAMME ");
            break;
        }
    } 
        }
    