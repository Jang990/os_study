#include <stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid;

    // 자식은 이명령어를 실행중인 PCB를 그대로 복사하기 때문에 fork()부터 수행함
    pid = fork(); // 자식을 만들어냄
    printf("Hello Process %d!\n", pid);

    return 0;
}