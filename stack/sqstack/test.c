#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sqstack.h"

int main(){

    sqstack *s;
    s = stack_create(100);
    if(s == NULL){
        return -1;
    }
    stack_push(s, 10);
    stack_push(s, 20);
    stack_push(s, 30);
    stack_push(s, 40);
    while(!stack_empty(s)){
        printf("pop: %d\n", stack_pop(s));
    }
    stack_free(s);
    s = NULL;
    return 0;

}