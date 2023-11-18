#include <stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid;

    pid = fork();
    if(pid > 0) // 부모 pid는 0이 아님
        wait(NULL); // 즉 부모는 wait 큐에 들어가 자식 프로세스가 종료하고 인터럽트를 주길 기다림

    printf("Hello Process %d!\n", pid);

    return 0;
}