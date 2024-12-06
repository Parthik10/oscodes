#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf { long mtype; char mtext[100]; };

int main() {
    int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    struct msgbuf message = {1, "Hello, message!"};
    msgsnd(msgid, &message, sizeof(message.mtext), 0);
    msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);
    printf("Received: %s\n", message.mtext);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
