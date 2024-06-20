#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void static inline errExit(const char* msg)
{
	printf("%s failed. Exiting the process\n", msg);
	exit(-1);
}

int main()
{
	void *curr_brk, *tmp_brk = NULL;

	printf("这是一个brk/sbrk使用的例子！\n");
	// sbrk(0) 获取当前 program break 位置 
	tmp_brk = curr_brk = sbrk(0);
	printf("当前Program Break位置是:%p\n", curr_brk);
	printf("也可以另起一个命令行查看虚拟地址空间中heap状态，命令是 cat /proc/%d/maps\n", getpid());
	printf("然后按任意键继续...\n");
	getchar();

	// 使用 brk 增加 program break 位置 
	brk(curr_brk+4096);
	curr_brk = sbrk(0);
	printf("brk增加4096字节后，当前Program Break位置变成了:%p\n", curr_brk);
	printf("然后按任意键继续...\n");

	getchar();

	// 使用 brk 减小 program break 位置 
	brk(tmp_brk);
	curr_brk = sbrk(0);
	printf("brk缩小4096字节后，当前Program Break位置回到了:%p\n", curr_brk);
	printf("然后按任意键退出程序...\n");
	getchar();

	return 0;
}