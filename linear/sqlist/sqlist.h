//接口：数据长什么样（定义 sqlist），函数声明 list_insert 
#define N 100

typedef int data_t;
typedef struct{

    data_t data[N];
    int last;

}sqlist,*sqlink;

sqlink list_create();
int list_clear(sqlink L);
int list_empty(sqlink L);
int list_length(sqlink L);
int list_locate(sqlink L,data_t value);
int list_insert(sqlink L,data_t value,int pos);