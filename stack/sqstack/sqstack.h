typedef int data_t;//定义栈中数据元素的数据类型
typedef struct{

    data_t *data;//用指针指向栈的存储空间
    int maxlen;//当前栈的最大元素个数
    int top;//指示栈顶位置（数组下标）的变量

}sqstack;

sqstack *stack_create(int len);

