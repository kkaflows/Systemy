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

	
	int msqid;	
	key_t key;
	struct msgbuf rcv;

	key = 3241;

	msqid = msgget(key, 0666);
	if(msqid == -1){
	printf("blad msgget");	
	}else{
	printf("sukces msgget %d", msqid);
	}

	if(msgrcv(msqid, &rcv, MSGSZ, 1, 0) <0){
	printf("nie udalo sie odebrac komunikatu");
	};


	printf("komunikat odebrany to: %s", rcv.mtext);
	


return 0;
}
