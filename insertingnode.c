#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    // struct node *prev;
};

struct node *head;

void insert_beg()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("\nENTER THE ELEMENT:");
        scanf("%d", &item);
        if (head == NULL)
        {
            ptr->data = item;
            ptr->next = NULL;
            // ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            // ptr->prev = NULL;
            ptr->next = head;
            // head->prev = ptr;
            head = ptr;
        }
    }
}

void insert_last()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("\nENTER VALUE: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            // ptr->prev = NULL;
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
            // ptr->prev = temp;
            ptr->next = NULL;
        }
    }
}

void insert_specified()
{
    struct node *ptr, *temp;
    int item, loc, i;
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
        ptr->data = item;
        ptr->next = temp->next;
        // ptr->prev = temp;
        temp->next = ptr;
        // temp->next->prev = ptr;
    }
}

void deletion_beg()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOWN");
        // }else if(head->next=NULL){
        //     head=NULL;
        //     free(head);
    }
    else
    {
        ptr = head;
        head = head->next;
        // head->prev = NULL;
        free(ptr);
    }
}

void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOWN");
        //     }else if(head->next==NULL){
        //         head=NULL;
        //         free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        struct node *temp =ptr->next;
        ptr->next=NULL;
        free(temp);
    }
}

void deletion_specified()
{
    struct node *ptr, *temp;
    int val;
    printf("\n ENTER THE DATA AFTER WHICH NODE IS TO BE DELETED");
    scanf("%d", &val);
    ptr = head;
    while (ptr->data != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("\n CAN'T DELETE \n");
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        // temp->next->prev = ptr;
        free(temp);
    }
}

void display()
{

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
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
        printf("1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete at specified\n7.Show\n8.Exit\n");
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
            deletion_beg();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            deletion_specified();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("\nTHE END\n");
            exit(0);
        default:
            printf("NOT VALID\n");
        }
    }
    return 0;
}
