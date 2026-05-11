#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"

int main(){

    linkstack s;
    if((s = stack_create()) == NULL){
        return -1;
    }
    stack_push(s, 10);
    stack_push(s, 20);
    stack_push(s, 30);
    stack_push(s, 40);
    while(!stack_empty){
        printf("pop: %d\n", stack_pop(s));
    }
    s = stack_free(s);
    return 0;
}