//shared memory 
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    char *str = shmat(shmid, NULL, 0);
    strcpy(str, "Hello from shared memory!");
    printf("Data: %s\n", str);
    shmdt(str); shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
 