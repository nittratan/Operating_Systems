#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer
{
    long msg_type;
    char msg_text[100];
} message;

int main()
{
    key_t key;
    int msgid;

    key = ftok("process", 110);

    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    printf("Message Received is : %s \n", message.msg_text);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
