#include<stdio.h>
#include<stdio.h>
int stack[5];
int size= 5;
int top=-1;
int i;
void push(){
    if(top==size-1){
        printf("stack overflown\n");
    }else{
        top= top+1;
        printf("enter the element to entered: ");
        scanf("%d", &stack[top]);
    }
}

void pop(){
    if(top==-1){
        printf("stack underflown\n");
    }else{
        printf("the element to popped %d", stack[top]);
        top=top-1;

    }
}
void display(){
    if(top==-1){
        printf("stack underflown");
    }else{
        printf("the STACK is:-\n");
        for(i=top;i>=0;i--){
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
    int key;
    printf("welcome to stack programme:-\n");
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