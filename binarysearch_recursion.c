#include<stdio.h>
#include<stdio.h>

void binarysearch(int list[],int l,int h,int key){
    int mid;
    if(l>h){
        printf("key not found\n");
        return;
    }
    mid=(l+h)/2;
    if(list[mid]==key){
        printf("key found\n");
    }else if(list[mid]>key){
        binarysearch(list,l,mid-1,key);
    }else if(list[mid]<key){
        binarysearch(list,mid+1,h,key);
    }
}

void main(){
    int key,size,i;
    int list[25];
    printf("give the size of list: ");
    scanf("%d", &size);
    printf("enter the elements in ascending oreder: \n");
    for(i=0;i<size;i++){
        scanf("%d", &list[i]);
    }
    printf("enter the key: ");
    scanf("%d", &key);
    binarysearch(list,0,size,key);
}
