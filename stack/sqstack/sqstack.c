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