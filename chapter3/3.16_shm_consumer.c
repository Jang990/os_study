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

    // READ 옵션만 넣고 파일을 가져와서 printf로 읽으면 끝.
    shm_fd = shm_open(name, O_RDONLY, 0666);
    ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    printf("%s", (char *)ptr);
    shm_unlink(name);
    
    return 0;
}

