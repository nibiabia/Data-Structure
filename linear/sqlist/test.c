//调用与测试 试吃员 / 

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"sqlist.h"

void test_mylist();

int main(void){

    test_mylist();
    return 0;
}


void test_mylist(){
    sqlink L;
    L = list_create();
    if(L == NULL){
        return;
    }
    list_insert(L,10,0);
    list_show(L);
    list_delete(L);
    L = NULL;
}