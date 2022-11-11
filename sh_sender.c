#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
void *shm;
char buffer[100];
int shmid;
shmid=shmget((key_t)596,1024,IPC_CREAT|0666);
printf("key of shared memory is %d\n",shmid);
shm=shmat(shmid,NULL,0);
printf("process attached at address:%p\n",shm);
printf("enter some data to write in the shared memory\n");
read(0,buffer,100);
strcpy(shm,buffer);
printf("input recived is :%s\n",(char*)shm);
}
