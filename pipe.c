#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
int fd[2],n;
char buffer[100],msg[80]="I dont know why i am doing this but sounds fun\n";
pid_t p;
pipe(fd);
p=fork();
if(p>0)
{
printf("passing values to children\n");
write(fd[1],msg,sizeof(msg));
}
else{
printf("child recieved data just like real life\n");
n=read(fd[0],buffer,100);
write(1,buffer,n);
}
 return 0;
}
