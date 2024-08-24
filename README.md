
本工程是《深入理解Linux进程与内存 - 修炼底层内功、掌握高性能原理》一书的配套代码。

大家也可以加飞哥微信（zhangyanfei748528）进读者交流群。

**敬请扫码关注微信公众号「开发内功修炼」，及时获得最新硬核文章！**   
![avatar](imgs/official_accounts.jpg)   


## 书中相关开源代码
- glibc源码下载地址：
	- 官网：[http://ftp.gnu.org/gnu/glibc/](http://ftp.gnu.org/gnu/glibc/) 
	- 清华大学开源软件镜像： [https://mirrors.tuna.tsinghua.edu.cn/gnu/libc/](https://mirrors.tuna.tsinghua.edu.cn/gnu/libc/) 
- Golang源码下载地址：[https://github.com/golang/go](https://github.com/golang/go) 
- libcontainer源码地址：[https://github.com/opencontainers/runc/tree/main/libcontainer](https://github.com/opencontainers/runc/tree/main/libcontainer) 
- CAdvisor源码地址：[https://github.com/google/cadvisor](https://github.com/google/cadvisor) 
- Linux源码下载地址：[https://mirrors.edge.kernel.org/pub/linux/kernel/](https://mirrors.edge.kernel.org/pub/linux/kernel/) 
- lxcfs源码下载地址：[https://github.com/lxc/lxcfs](https://github.com/lxc/lxcfs) 
- Nginx源码下载地址：[https://github.com/nginx/nginx](https://github.com/nginx/nginx) 
- redis 源码下载地址：[https://github.com/redis/redis](https://github.com/redis/redis) 
- 内核在线源码阅读网站：[http://elixir.bootlin.com/](http://elixir.bootlin.com/) 
- 书的配套实验：[https://github.com/yanfeizhang/deep_linux_process_tests](https://github.com/yanfeizhang/deep_linux_process_tests)

## 书中实验源码
- 第二章
	- [内存延时性能测试](chapter-02/test-01)
	- [内存带宽性能测试](chapter-02/test-01)
- 第四章
	- [查看ELF文件格式用的demo程序](chapter-04/test-01)
- 第六章
	- [堆栈溢出程序](chapter-06/test-01)
	- [查看进程虚拟地址空间状态](chapter-06/test-02)
	- [使用mmap匿名映射后的进程虚拟地址空间状态](chapter-06/test-03)
	- [使用brk/sbrk后的进程虚拟地址空间状态](chapter-06/test-04)
- 第七章
	- [进程上下文切换开销测试](chapter-07/test-01)
	- [线程上下文切换开销测试](chapter-07/test-02)
- 第八章
	- [直接使用内核伪文件来计算CPU利用率](chapter-08/test-01)
- 第九章
	- [协程上下文切换测试](chapter-09/test-01)
- 第十二章
	- [容器内存限制实验](chapter-12/test-01)	
- 第十三章
	- [C语言函数工作原理](chapter-13/test-01)
	- [Golang函数工作原理](chapter-13/test-02)
	- [read系统调用开销测试](chapter-13/test-03) 
	- [](chapter-13/test-06) 多出来的
- 第十四章
	- [火焰图工作原理查看代码](chapter-14/test-01)
	- [使用内核系统调用查看硬件指标](chapter-14/test-02)
- 第十五章
	- [根据内核伪文件计算进程的CPU利用率](chapter-15/test-01)
	- [根据内核伪文件计算容器的CPU利用率](chapter-15/test-02)
- 第十六章
	- [内核中的likely与unlikely](chapter-16/test-01)


## 公众号
扫一扫关注公众号「开发内功修炼」，获取最新硬核技术文章！  
![](imgs/official_accounts.jpg) 

## 技术交流 && 意见反馈
添加作者微信加技术交流群，或者反馈您宝贵的改进建议！  
![](imgs/author.png) 

## 书籍勘误列表
- [书籍勘误列表](changelogs/index.md)

