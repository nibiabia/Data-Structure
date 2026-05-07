typedef int data_t;//定义栈中数据元素的数据类型
typedef struct{

    data_t *data;//用指针指向栈的存储空间
    int maxlen;//当前栈的最大元素个数
    int top;//指示栈顶位置（数组下标）的变量

}sqstack;

sqstack *stack_create(unsigned int len);
int stack_empty(sqstack *s);//判断栈是否为空
int stack_full(sqstack *s);//判断栈是否满了
int stack_push(sqstack *s, data_t value);//入栈
data_t stack_pop(sqstack *s);//出栈
int stack_clear(sqstack *s);//栈内容清空
int stack_free(sqstack *s);//栈的释放

