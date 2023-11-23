#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0;
void * runner(void *param);
int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_attr_t attr; // 안써도 상관없음 - 책에 있으니까 추가.
    // attr은 스레드의 스택 크기, 스케줄링 우선순위, 스레드의 종료 동작 등을 설정

    pthread_attr_init(&attr); // 일단 기본값으로 설정
    pthread_create(&tid, &attr, runner, (void *)argv[1]); // 자바 new Thread 부분
    // pthread_create(&tid, NULL, runner, (void *)argv[1]); // attr은 NULL로 넣어도 상관없음

    pthread_join(tid, NULL); // 자바 thread.join 부분
    printf("%d\n", sum);
    return 0;
}

// 자바 Thread의 void run();
void *runner(void *param)  // argv[1]이 넘어 온다.
{
    int i, upper = atoi(param); // string을 int로 변환
    sum = 0;
    for(i = 1; i <= upper; i++)
        sum += i;
    pthread_exit(0);
}
