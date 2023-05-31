#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
int pid;
pid = fork();
if(pid==0){
printf("I am child, my process ID is %d\n", getpid());
printf("The parent process ID is %d\n", getppid());
}
else{
printf("I am parent, my process ID is %d\n", getpid());
printf("The parent process ID is %d\n", getppid());
}
return 0;
}