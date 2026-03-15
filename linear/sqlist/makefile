# 定义编译器
CC = gcc
# 定义编译选项：-Wall (显示所有警告), -g (添加调试信息)
CFLAGS = -Wall -g

# 目标文件：最终生成 test
test: test.o sqlist.o
	$(CC) $(CFLAGS) test.o sqlist.o -o test

# 编译 test.o
test.o: test.c sqlist.h
	$(CC) $(CFLAGS) -c test.c -o test.o

# 编译 sqlist.o
sqlist.o: sqlist.c sqlist.h
	$(CC) $(CFLAGS) -c sqlist.c -o sqlist.o

# 清理编译生成的文件
clean:
	rm -f *.o test