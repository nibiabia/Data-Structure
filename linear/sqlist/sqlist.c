//sqlist.c 实现 / Implementation

#include"sqlist.h" //(双引号)： 编译器会先在项当前目目录下找文件
#include<stdio.h>
#include<stdlib.h>//包含malloc函数
#include<string.h>//包含memset函数

sqlink list_create(){

    sqlink  L;
    //第一步：申请内存
    L = (sqlink)malloc(sizeof(sqlist));
    if(L == NULL){
        printf("Malloc failed!\n");//给用户一个提示：
        // 内存分配失败，放回一个特殊类型的指针：NULL
        return NULL;
    }
    //第二步：初始化
    memset(L,0,sizeof(sqlist));//从L开始的sizeof(sqlist)个字节都用0来填充
    L->last = -1;//last代表该数组最后一个有效元素的下标（0-N-1），一个数组的下标不可能为-1;
    // 结构体的指针访问结构体的成员用->
    //第三步：返回值
    return L;

};

int list_clear(sqlink L){

    if(L == NULL){
        return -1;
    }
    memset(L,0,sizeof(sqlist));
    L->last = -1;
    return 0;

};

int list_free(sqlink L){
    if(L == NULL){
        return -1;
    }
    free(L);
    return 0;
}

int list_empty(sqlink L){

    return (L->last == -1);
    //检查sqlist是否为空：1代表空，0代表非空
};

int list_length(sqlink L){

    if(L == NULL){
        return -1;
    }
    return (L->last + 1);

};

int list_locate(sqlink L,data_t value){
    
    for(int i = 0;i <= L->last;i++){
        if(L->data[i] == value){
            return i;
        }
    }
    return -1;

};

int list_insert(sqlink L,data_t value,int pos){
    
    //1.check full
    if(L->last == N-1){
        printf("List is already full\n");
        return -1;
    }
    //2.check pos   顺序表必须是连续存储的，所以pos必须位于[0，L->last+1]
    if(pos < 0 || pos > L->last + 1){
        printf("Pos is invalid\n");
        return -1;
    }
    //3.move  从后往前移
    for(int i = L->last;i >= pos;i--){
        L->data[i+1] = L->data[i];
    }
    //4.update value last
    L->data[pos] = value;
    L->last++;
    return 0;

}


int list_show(sqlink L){   //顺序表遍历

    if(L == NULL){
        return -1;
    }
    if(L->last == -1){
        printf("List is empty\n");
        return 0;
    }
    for(int i = 0;i <= L->last;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
    return 0;

}


int list_delete(sqlink L,int pos){

    if(L == NULL){
        return -1;
    }
    if (L->last == -1){
        printf("List is empty\n");
        return -1;
    }
    if(pos < 0 || pos > L->last){
        printf("Delete pos is invalid\n");
        return -1;
    }
    for(int i = pos+1;i <= L->last;i++){
        L->data[i-1] = L->data[i];
    }
    L->last--;
    return 0;

}


int list_merge(sqlink L1, sqlink L2){
    for(int i = 0;i <= L2->last;i++){
        if(list_locate(L1,L2->data[i]) == -1){
            if(list_insert(L1,L2->data[i],L1->last+1) == -1){
                return -1;
            }
        }
    }
    return 0;
}

int list_purge(sqlink L){
    if(L->last <= 0){
        return 0;
    }
    int i = 1;
    while(i <= L->last){
        int j;
        for(j = i - 1;j >= 0;j--){
            if(L->data[j] == L->data[i]){
                list_delete(L,i);
                break;
            }
         }
        if(j < 0){
            i++;
         }
    }
    return 0;
}