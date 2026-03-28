#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

linklist list_create(){

    linklist H;
    H = (linklist)malloc(sizeof(listnode));
    if(H == NULL){
        printf("Malloc failed.\n");
        return NULL;
    }
    H->data = 0;
    H->next = NULL;
    return H;

}

int list_tail_insert(linklist H, data_t value){

    if(H == NULL){
        printf("H is NULL.\n");
        return -1;
    }
    //包装成一个节点：1.申请内存 2.赋值
    linklist p;
    if((p = (linklist)malloc(sizeof(listnode))) == NULL){
        printf("Malloc failed.\n");
        return -1;
    }
    p->data = value;
    p->next = NULL;
    //寻找尾结点
    linklist q;
    q = H;
    while(q != NULL){
        q = q->next;
    }
    //尾部插入
    q = p;
    return 0;

}

int list_show(linklist H){
    
    if(H == NULL){
        printf("H is NULL.\n");
        return -1;
    }
    while(q->next != NULL){
        printf("%d ",q->next->data);
    }
    printf("\n");
    return 0;
    
}

