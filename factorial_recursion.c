#include<stdio.h>
#include<stdlib.h>

int factorial(int x){
    if(x<2){
        return 1;
    }else{
       return x*(factorial(x-1));
    }
    

}
int main(){
    int val;
    printf("give value of element: ");
    scanf("%d", &val);
   printf( "%d",factorial(val));
    return 0;
}