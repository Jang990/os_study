#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int value = 0;
void * runner(void *param);
int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    pid_t pid;

    pid = fork();
    if(pid == 0) {
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("자식 Value : %d\n", value);
    } else if(pid > 0) {
        wait(NULL);
        printf("부모 Value : %d\n", value);
    }

    return 0;
}

void *runner(void *param)
{
    value = 5;
    pthread_exit(0);
}
