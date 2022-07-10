/*************************************************************************
    > File Name: main.c
    > Author: Rytonli
    > Mail: rytonli@163.com
    > Created Time: Sun 10 Jul 2022 03:08:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "epoll_server.h"

int main(int argc, char* argv[]){
	if(argc < 3)
    {
        printf("eg: ./a.out port path\n");
        exit(1);
    }

    // 采用指定的端口
    int port = atoi(argv[1]);

    // 修改进程工作目录, 方便后续操作
    int ret = chdir(argv[2]);
    if(ret == -1)
    {
        perror("chdir error");
        exit(1);
    }
    
    // 启动epoll模型 
    epoll_run(port);

  return 0;
}
