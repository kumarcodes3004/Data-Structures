#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
int item;
int check_duplicate(){
    struct node* temp =head;
    while(temp!=    NULL){
        if(temp->data==item){
            return 0;
        }else{
            temp=temp->next;
        }
    }
    return 1;
}

void insert_beg()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    // int item;
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("\nENTER THE ELEMENT:");
        scanf("%d", &item);
        if(check_duplicate()==1){

        
        if (head == NULL)
        {
            ptr->data = item;
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
    }else{
        printf("DUPLICATE ITEM \n");
        
    }
}
}

void insert_last()
{
    struct node *ptr, *temp;
    // int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("\nENTER VALUE: ");
        scanf("%d", &item);
        if(check_duplicate()==1){
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }else{
         printf("DUPLICATE ITEM \n"); 
    }
    }
}

void insert_specified()
{
    struct node *ptr, *temp;
    int  loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        temp = head;
        printf("ENTER THE LOCATION:");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("THERE ARE LESS THAN %d ELEMENTS\n", loc);
            }
        }
        printf("GIVE THE VALUE: ");
        scanf("%d", &item);
        if(check_duplicate()==1){
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
    }else{
        printf("DUPLICATE ITEM \n");
    }
    }
}

void display(){

    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


int main()
{
    int choice;

    printf("\n DOUBLY LINKED LIST \n ");
    printf("choose from menu\n");
    while (1 > 0)
    {
        printf("1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Show\n5.Exit\n");
        printf("give ur choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_specified();
            break;
        case 4:
            display();
            break;
        case 5:
              printf("\nTHE END\n");
            exit(0);
            break;
      
        default:
            printf("NOT VALID\n");
        }
    }
    return 0;
}
