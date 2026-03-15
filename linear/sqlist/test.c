//调用与测试 试吃员 / 

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"sqlist.h"

int main(void){

    sqlink L;
    L = list_create();
    if(L == NULL){
        return -1;
    }
    list_insert(L,10,0);

    return 0;
}