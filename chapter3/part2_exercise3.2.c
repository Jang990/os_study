#include <stdio.h>
#include<unistd.h>
#include <sys/wait.h>


int main() 
{
    // 몇 개의 프로세스가 생성됐을까?
    pid_t pid;
    pid = fork();
    pid = fork();
    pid = fork();

    printf("Hello fork() %d!\n", pid); // 자식은 0
    return 0;
}

// 8