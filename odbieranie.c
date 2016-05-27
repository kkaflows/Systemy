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
	int dl; 

	key = 3241;

	msqid = msgget(key, 0666);
	if(msqid == -1){
	printf("blad msgget");	
return -1;
	}else{
	printf("sukces msgget %d \n", msqid);
	}

	if(msgrcv(msqid, &rcv, MSGSZ, 1, 0) <0){
	printf("nie udalo sie odebrac komunikatu");
return -1;
	};

	dl = strlen(rcv.mtext);
	int ileLiter= 0;

	//jak nie zaczyna sie od znaku to nie ma sensu sprawdzania dalej
	if(((rcv.mtext[0] >= 65) && (rcv.mtext[0] <= 90)) || ((rcv.mtext[0] >= 97) && (rcv.mtext[0] <= 122))){
		ileZnakow+;
	for(int i = 1; i<dl; i++){
	if(((rcv.mtext[i] >= 32) && (rcv.mtext[i] <= 126))  {
		ileZnakow++;
		}
	}
}else{
	printf("komunikat nie jest poprawny: nie zaczyna sie od litery");
}
	if(dl == ileZnakow){
	printf("komunikat jest poprawny i brzmi: %s", rcv.mtext);
	}
	


return 0;
}
