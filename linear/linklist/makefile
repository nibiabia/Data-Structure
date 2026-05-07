# 定义编译器
CC = gcc

# 定义编译选项：-Wall 开启所有警告，-g 包含调试信息（方便后期 gdb 调试）
CFLAGS = -Wall -g

# 定义最终生成的可执行文件名称
TARGET = test

# 定义目标对象文件
OBJS = test.o linklist.o

# 默认目标：链接所有的 .o 文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译 test.c 生成 test.o，依赖 linklist.h 头文件
test.o: test.c linklist.h
	$(CC) $(CFLAGS) -c test.c

# 编译 linklist.c 生成 linklist.o，依赖 linklist.h 头文件
linklist.o: linklist.c linklist.h
	$(CC) $(CFLAGS) -c linklist.c

# 伪目标，用于清理编译产生的中间文件和可执行文件
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)