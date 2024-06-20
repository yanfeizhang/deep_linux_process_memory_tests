#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void static inline errExit(const char* msg)
{
	printf("%s failed. Exiting the process\n", msg);
	exit(-1);
}

int main()
{
	int ret = -1;
	printf("这是一个mmap匿名映射的例子！\n");
	printf("请另起一个命令行查看虚拟地址空间状态，命令是 cat /proc/%d/maps\n", getpid());
	printf("然后按任意键继续...\n");

	getchar();
	char* addr = NULL;
	addr = mmap(NULL, (size_t)132*1024, PROT_READ|PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (addr == MAP_FAILED)
		errExit("mmap错误");
	printf("mmap私有映射成功，再次查看虚拟地址空间状态，观察有什么变化\n");
	printf("然后按任意键继续...\n");

	getchar();
	ret = munmap(addr, (size_t)132*1024);
	if(ret == -1)
		errExit("munmap错误");
	printf("接触mmap私有映射成功，再次查看虚拟地址空间状态，观察有什么变化\n");
	printf("然后按任意键退出程序...\n");
	
	getchar();
	return 0;
}