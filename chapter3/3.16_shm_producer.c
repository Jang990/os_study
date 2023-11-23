#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    int shm_fd;
    char *ptr;
    const char *name = "OS";
    const int SIZE = 4096;
    const char *message_0 = "Hello, ";
    const char *message_1 = "Shared Memory\n";

    // shm_fd = shm_open("OS", O_CREAT | O_RDWR, 0666);
    shm_fd = shm_open( // Shared 메모리 열기
        name, // 이름 "OS"
        O_CREAT | O_RDWR, // 파일이 없으면 생성 | 파일을 읽기/쓰기용으로 연다
        0666); // 리눅스에서 RWX = 7(4+2+1)이고 RW는 6(4+2), R = 4이다. (소유자, 그룹, 다른 사용자 순)
        // 맨앞에 0은 setuid, setgid 및 sticky 비트에 대한 설정을 나타내는 숫자.

    ftruncate(shm_fd, SIZE); // Shared 메모리 크기를 4096 바이트로 설정
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); // 메모리에 연결

    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0); // 내용이 겹쳐서 누락되지 않게 문자열 길이만큼 in을 뒤로 민다.
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_0); // in을 뒤로 민다.
    
    return 0;
}

