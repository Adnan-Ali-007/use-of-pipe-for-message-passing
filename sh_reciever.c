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
shmid=shmget((key_t)596,1024,0666);
printf("key of shared memory is %d\n",shmid);
shm=shmat(shmid,NULL,0);
printf("process attached at %p \n",shm);

printf("data read from shared memory is:%s \n",(char*)shm);

}
