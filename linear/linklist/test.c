#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void test_delete();
void test_get();
void test_insert();
void test_adjmax();
void test_reverse();

int main(){

    test_get();
    return 0;

}

void test_get(){

    linklist H;
    H = list_create();
    if(H == NULL){
        return;
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
    p = list_get(H,4);
    list_free(H);
    H = NULL;

}

void test_insert(){

    linklist H;
    H = list_create();
    if(H == NULL){
        return;
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
    list_insert(H, 100, 2);
    list_insert(H, 20, 5);
    list_show(H);
    list_free(H);
    H = NULL;

}

void test_delete(){

    linklist H;
    H = list_create();
    if(H == NULL){
        return;
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
    list_delete(H, 0);
    list_delete(H, 5);
    list_show(H);
    list_free(H);
    H = NULL;

}

void test_reverse(){

    linklist H;
    H = list_create();
    if(H == NULL){
        return;
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
    list_reverse(H);
    list_show(H);
    list_free(H);
    H = NULL;
    
}

void test_adjmax(){

    linklist H;
    H = list_create();
    data_t value;
    while(1){
        printf("Input:");
        scanf("%d",&value);
        if(value == -1){
            break;
        }
        list_tail_insert(H,value);
    }
    list_show(H);
    data_t max;
    linklist r = list_adjmax(H, &max);
    if(r != NULL && r != H){
         printf("%d\n",r->data);
         printf("%d\n",max);
    }
    list_free(H);
    H = NULL;

}