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
        q = q->next;//p不断指向下一个结点
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