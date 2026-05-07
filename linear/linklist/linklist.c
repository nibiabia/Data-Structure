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
    while(q->next != NULL){
        q = q->next;//p不断指向下一个结点
    }
    //尾部插入
    q->next = p;
    return 0;

}

int list_show(linklist H){
    
    if(H == NULL){
        printf("H is NULL.\n");
        return -1;
    }
    linklist q = H;
    while(q->next != NULL){
        printf("%d ",q->next->data);
        q = q->next;
    }
    printf("\n");
    return 0;
    
}

linklist list_get(linklist H, int pos){//通常底层的数据获取函数（如 get）不需要负责打印错误信息（保持静默），只需返回 NULL。
// 把打印错误信息的责任交给调用它的上层函数（如 delete、insert 等）或者主函数，这样可以避免错误信息重复打印。

    if(H == NULL){
        printf("H is NULL.\n");
        return NULL;
    }
    if(pos < -1){
        return NULL;
    }
    linklist q;
    q = H;
    for(int i = -1;i < pos;i++){
         q = q->next;
         if(q == NULL){
            break;
         }
    }
    return q;

}

int list_insert(linklist H, data_t value, int pos){

    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    linklist p;
    p = list_get(H, pos - 1);
    if(p == NULL){
        printf("Pos is invalid\n");
        return -1;
    }
    //在确认所有前置条件都合法、确实需要执行操作时，再去申请资源
    linklist q;
    if((q = (linklist)malloc(sizeof(listnode))) == NULL){
        printf("Malloc failed.\n");
        return -1;
    }
    q->data = value;
    q->next = NULL;
    q->next = p->next;//
    p->next = q;//顺序不能反
    return 0;

}

int list_delete(linklist H, int pos){

    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    linklist p = list_get(H, pos - 1);
    if(p == NULL){
        printf("Pos is invalid\n");
        return -1;
    }
    if(p->next == NULL){
        printf("Pos is invalid\n");
        return -1;
    }
    linklist q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;
    return 0;

}

int list_free(linklist H){

    if(H ==NULL){
        printf("H is NULL\n");
        return -1;
    }
    linklist q = H;
    linklist p;
    while(q != NULL){
        p = q->next;
        free(q);
        q = p;
    }
    return 0;

}//调用完list_free后，还要在后面手动将头指针置为NULL 

int list_reverse(linklist H){

    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    if(H->next == NULL || H->next->next == NULL){//空链表或者只有一个结点
        return 0;
    }

    linklist p = H->next->next;
    H->next->next = NULL;//把链表分成两部分

    linklist q;
    while(p != NULL){
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
    return 0;

}

linklist list_adjmax(linklist H, data_t *max){

    if(H == NULL){
        printf("H is NULL\n");
        return NULL;
    }
    if(H->next == NULL || H->next->next == NULL){
        *max = 0;
        return H;
    }
    linklist p = H->next;
    linklist q = H->next->next;
    linklist r = p;
    *max = p->data + q->data;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        data_t sum = q->data + p->data;
        if(sum > *max){
            *max = sum;
            r = p;
        }
    }
    return r;

}

int list_merge(linklist H1, linklist H2){//尾插法（Tail Pointer）。
//思路概括为：“把 H1 和 H2 的节点全拆散，谁小就捡起谁，排成一条新队伍

    if(H1 == NULL || H2 == NULL){
        printf("H1 || H2 is NULL\n");
        return -1;
    }
    linklist p, q, r;
    p = H1->next;
    q = H2->next;
    r = H1;
    H1->next = NULL;
    H2->next = NULL;
    while(p && q){
        if(p->data <= q->data){
            r->next = p;
            p = p->next;
        }else{
            r->next = q;
            q = q->next;
        }
        r = r->next;
        r->next = NULL;
    }
    if(p == NULL){
        r->next = q;
    }else{
        r->next = p;
    }
    return 0;

}