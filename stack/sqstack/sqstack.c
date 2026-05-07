#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sqstack.h"

sqstack *stack_create(unsigned int len){

    sqstack *s;
    if((s = (sqstack *)malloc(sizeof(sqstack))) == NULL){
        printf("Malloc sqstack failed\n");
        return NULL;
    }
    if((s->data = (data_t *)malloc(sizeof(data_t) * len)) == NULL){
        printf("Malloc data_array failed\n");
        free(s); // [修正点]：释放前面已经成功分配的结构体内存
        return NULL;
    }
    //两个都malloc成功后再赋初值
    memset(s->data, 0, sizeof(data_t) * len);
    s->maxlen = len;
    s->top = -1;//数组下标，此时数组中没有元素，为空
    
    return s;

}
/*
@return 1-empty 0-not empty -1-error
*/
int stack_empty(sqstack *s){

    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    return (s->top == -1 ? 1 : 0);

}

/*
@return 1-full 0-not full -1-error
*/
int stack_full(sqstack *s){

    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    return (s->top == s->maxlen -1 ? 1 : 0);

}

int stack_push(sqstack *s, data_t value){

    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    if(s->top == s->maxlen - 1){
        printf("sqstack is full\n");
        return -1;
    }
    s->top++;
    s->data[s->top] = value;
    return 0;

}

data_t stack_pop(sqstack *s){

    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    if(s->top == -1){
        printf("sqstack is empty\n");
        return -1;
    }
    s->top--;
    return s->data[s->top + 1];

}
/*
@return 0-success -1-error
*/
int stack_clear(sqstack *s){

    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    s->top = -1;
    return 0;

}

/*
@return 0-success -1-error
*/
int stack_free(sqstack *s){

    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    free(s->data);
    free(s);
    return 0;
    
}
