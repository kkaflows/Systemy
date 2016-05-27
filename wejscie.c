#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define MSGSZ	128

struct msgbuf{
	long mtype;
	char mtext[MSGSZ];
};

int main(){

	
	int msgflg = IPC_CREAT | 0666;
	
	int msqid;
	key_t key;
	size_t dl;

	key = 3241;
	
	struct msgbuf msg;
	msg.mtype = 1;
	
	//strcpy(msg.mtext, "test");	
	scanf("%[^\n]",msg.mtext);
	printf("%s", msg.mtext);
	dl = strlen(msg.mtext) + 1;

	
	msqid = msgget(key, msgflg);
	if(msqid == -1){
	perror("msgget failed");
	return;
	}else{
	printf("msgget succeeded. ID: %u \n", msqid);
	}

	if((msgsnd(msqid, &msg, dl, 0)) == -1){
	printf("nie udalo sie wyslac wiadomosci");	
	return -1;
	}
	
	



return 0;
}
