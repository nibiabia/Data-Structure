#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"

linkstack stack_create(){

    linkstack s;
    if((s = (linkstack)malloc(sizeof(listnode))) == NULL){
        printf("Malloc failed\n");
        return NULL;
    }
    s->data = 0;
    s->next = NULL;
    return s;

}

int stack_push(linkstack s, data_t value){

    linkstack p;
    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    if((p = (linkstack)malloc(sizeof(listnode))) == NULL){
        printf("Malloc failed\n");
        return -1;
    }
    p->data = value;
    p->next = s->next;
    s->next = p;
    return 0;

}

data_t stack_pop(linkstack s){

    linkstack p;
    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    p = s->next;
    s->next = p->next;
    data_t value = p->data;
    free(p);
    return value;

}


/*
@return 1-empty 
*/
int stack_empty(linkstack s){

    if(s == NULL){
        printf("s is NULL\n");
        return -1;
    }
    return (s->next == NULL ? 1 : 0);
    
}

linkstack stack_free(linkstack s){

    linkstack p;
    if(s == NULL){
        printf("s is NULL\n");
        return NULL;
    }
    while(s != NULL){
        p = s;
        s = s->next;
        free(p);
    }
    return NULL;

}