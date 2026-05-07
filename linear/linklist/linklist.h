typedef int data_t;
typedef struct node{
    data_t data;//结点的数据域
    struct node *next;//后继结点的指针域
}listnode,*linklist;

linklist list_create();
int list_tail_insert(linklist H, data_t value);
int list_show(linklist H);
linklist list_get(linklist H, int pos);
int list_insert(linklist H, data_t value, int pos);
int list_delete(linklist H, int pos);
int list_free(linklist H);
int list_reverse(linklist H);
linklist list_adjmax(linklist H, data_t *max);
int list_merge(linklist H1, linklist H2);