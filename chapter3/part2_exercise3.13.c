#include <stdio.h>
#include<unistd.h>
#include <sys/wait.h>

// execlp
int main() 
{
    pid_t pid, pid1;
    pid = fork();

    if(pid == 0) {
        pid1 = getpid();
        printf("child fork() pid = %d\n", pid); // 0
        printf("child my pid = %d\n", pid1); // 1111(부모의 fork()결과와 같음)
    } else if (pid > 0) {
        pid1 = getpid();
        printf("parent fork() pid = %d\n", pid); // 2222
        printf("parent my pid = %d\n", pid1); // 1111(자식의 pid와 같음)
        wait(NULL);
    }

    return 0;
}