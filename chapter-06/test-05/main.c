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
	//打印各本地变量的内存地址
	double *d1 = (double *)malloc(sizeof(double));
	printf("0x%08x\n",d1); 
	double *d2 = (double *)malloc(sizeof(double));
	printf("0x%08x\n",d2);
	double *d3 = (double *)malloc(sizeof(double));
	printf("0x%08x\n",d3);
	double *d4 = (double *)malloc(sizeof(double));
	printf("0x%08x\n",d4);

	printf("按任意键退出程序...\n");
	getchar();
	return 0;
}