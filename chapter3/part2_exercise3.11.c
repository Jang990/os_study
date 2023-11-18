#include <stdio.h>
#include<unistd.h>
#include <sys/wait.h>


int main() 
{
    // 몇 개의 프로세스가 생성됐을까? 2
    int i;
    pid_t pid;

    for (i = 0; i < 4; i++)
        pid = fork();
    
    printf("Hello fork() %d!\n", pid); // 자식은 0
    return 0;
}

// 2^4 = 16