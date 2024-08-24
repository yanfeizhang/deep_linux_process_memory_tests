#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main() {
    int n;
    printf("请输入要申请的内存大小（单位：字节）：");
    scanf("%d", &n);

    // 申请指定大小的内存
    int* arr = (int*)malloc(n * sizeof(int)); 

    if (arr == NULL) {
        printf("内存申请失败!\n");
        return 1; // 如果内存申请失败则退出程序
    }

    // 对内存进行访问，以触发缺页中断真正分配物理内存
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; 
    }

    // 让程序休眠600秒方便观察
    sleep(600);

    // 释放内存
    free(arr);

    return 0; 
}
