//pipe communicaton
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2]; 
    char buffer[20];
    pipe(fd);
    if (fork() == 0) { // Child process
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else { // Parent process
        close(fd[0]);
        write(fd[1], "Hello, child!", 14);
        close(fd[1]);
    }
    return 0;
}
