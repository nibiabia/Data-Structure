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
    return 0;
}