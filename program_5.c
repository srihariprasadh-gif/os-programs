#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate unique key
    key = ftok("progfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Message Queue Created!\n");

    // ----------- SENDER -----------
    message.msg_type = 1;

    printf("Enter message: ");
    fgets(message.msg_text, 100, stdin);

    // Send message
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
    printf("Message sent!\n");

    // ----------- RECEIVER -----------
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);

    printf("Message received: %s", message.msg_text);

    // Delete message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
