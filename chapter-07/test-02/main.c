#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include<pthread.h>

int pipes[20][3];
char buffer[10];
int running = 1;

// 为实验建立管道
void init()
{
	int i =20;
	while(i--)
	{
		if(pipe(pipes[i])<0)
			exit(1);
		pipes[i][2] = i;
	}
}

// 关闭所有管道
void distroy()
{
	int i =20;
	while(i--)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
	}
}


// 测试管道开销
double pipe_test()
{
	int i =20000;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	while(i--)
	{
		if(write(pipes[0][1],buffer,10)==-1)
			exit(1);
		read(pipes[0][0],buffer,10);
	}
	gettimeofday(&end, NULL);
	return (double)(1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec)/20000;
}

void *thread_func(void *arg)
{
	int pos = ((int *)arg)[2];
	int in = pipes[pos][0];
	int to = pipes[(pos + 1)%20][1];
	while(running)
	{
		read(in,buffer,10);
		if(write(to,buffer,10)==-1)
			exit(1);
	}
}

double thread_switch_test()
{
	int i = 20;
	struct timeval start, end;
	pthread_t tid;
	while(--i)
	{
		pthread_create(&tid,NULL,thread_func,(void *)pipes[i]);
	}
	i = 10000;
	gettimeofday(&start, NULL);
	while(i--)
	{
		if(write(pipes[1][1],buffer,10)==-1)
			exit(1);
		read(pipes[0][0],buffer,10);
	}
	gettimeofday(&end, NULL);
	running = 0;
	if(write(pipes[1][1],buffer,10)==-1)
		exit(1);
	return (double)(1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec)/10000/20;
}


int main()
{
	init();

	// 测试管道开销
	printf("%6.6f\n", pipe_test());

	// 测试线程上下文切换开销
	printf("%6.6f\n", thread_switch_test());

	distroy();
	exit(0);
}
