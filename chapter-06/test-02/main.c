#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main()
{
	printf("请另起一个命令行查看虚拟地址空间状态，命令是 cat /proc/%d/maps\n", getpid());
	printf("然后按任意键退出程序...\n");
	getchar();
	return 0;
}