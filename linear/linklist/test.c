#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main(){

    linklist H;
    H = list_create();
    if(H == NULL){
        return -1;
    }
    data_t value;
    while(1){
        printf("Input:");
        scanf("%d", &value);
        if(value == -1){
            break;
        }
        list_tail_insert(H, value);
    }
    list_show(H);
    
    linklist p = list_get(H, 2);//1 3 5 7
    if(p != NULL){
        printf("value = %d\n",p->data);
    }
    return 0;
}