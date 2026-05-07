# 定义编译器
CC = gcc

# 定义编译选项：-Wall 显示所有警告，-g 添加调试信息
CFLAGS = -Wall -g

# 定义目标可执行文件名
TARGET = test

# 定义源文件
SRCS = test.c sqstack.c

# 将源文件列表中的 .c 替换为 .o (生成对象文件列表)
OBJS = $(SRCS:.c=.o)

# 默认规则：生成目标程序
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译每个 .c 文件生成 .o 文件
%.o: %.c sqstack.h
	$(CC) $(CFLAGS) -c $< -o $@

# 清理命令：输入 make clean 即可删除编译产物
clean:
	rm -f $(OBJS) $(TARGET)