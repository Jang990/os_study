#include <stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int value = 5; // 전역변수

// 전역변수는 어떻게 변했을까?
int main() 
{
    pid_t pid;
    pid = fork();
    if(pid == 0) { // 자식
        value += 15;
        return 0;
    } else if(pid > 0) { // 부모
        wait(NULL);
        printf("Parent value = %d\n", value);
    }
    return 0;
}