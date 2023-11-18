#include <stdio.h>
#include<unistd.h>
#include <sys/wait.h>

#define SIZE 5
int nums[SIZE] = {0, 1, 2, 3, 4};

// exercise 2와 똑같다. 배열이라고 다르지 않다.
int main() 
{
    pid_t pid;
    pid = fork();

    if(pid == 0) {
        for (int i = 0; i < SIZE; i++) {
            nums[i] *= i; // 곱해봄
            printf("Child : %d\n", nums[i]);
        }
        
    } else if (pid > 0) {
        wait(NULL);
        for (int i = 0; i < SIZE; i++)
            printf("Parent : %d\n", nums[i]); // 출력만
    }

    return 0;
}

// 영향 없음