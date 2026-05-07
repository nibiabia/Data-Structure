//调用与测试 试吃员 / 

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"sqlist.h"

void test_insert();
void test_delete();
void test_merge();
void test_purge();

int main(void){

    test_purge();
    return 0;
}





void test_insert(){
    sqlink L;
    L = list_create();
    if(L == NULL){
        return;
    }
    list_insert(L,10,0);
    list_show(L);
    list_free(L);
    L = NULL;
}

void test_delete(){
    sqlink L;
    L = list_create();
    if(L == NULL){
        return;
    }
    list_insert(L,10,0);
    list_insert(L,20,1);
    list_insert(L,30,2);
    list_show(L);
    list_delete(L,0);
    list_delete(L,6);
    list_show(L);
    list_free(L);
    L = NULL;
    
} 

void test_merge(){
    sqlink L1,L2;
    L1 = list_create();
    L2 = list_create();
    if(L1 == NULL){
        return;
    }
    if(L2 == NULL){
        return;
    }
    list_insert(L1,10,0);
    list_insert(L1,20,1);
    list_insert(L1,30,2);
    list_insert(L2,10,0);
    list_insert(L2,50,1);
    list_insert(L2,90,2);
    list_show(L1);
    list_show(L2);
    printf("-------------------------------\n");
    list_merge(L1,L2);
    list_show(L1);
    list_show(L2);
    list_free(L1);
    L1 = NULL;
    list_free(L2);
    L2 = NULL;

}


void test_purge(){
    sqlink L;
    L = list_create();
    if(L == NULL){
        return;
    }
    list_insert(L,10,0);
    list_insert(L,20,1);
    list_insert(L,10,2);
    list_insert(L,10,3);
    list_show(L);
    list_purge(L);
    list_show(L);
    list_free(L);
    L = NULL;
}