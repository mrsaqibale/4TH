#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
int pid,i;
pid = fork();
if(pid==0){
printf("I am child, my process ID is %d\n", getpid());
printf("The parent process ID is %d\n", getppid());
}
else{
printf("I am parent, my process ID is %d\n", getpid());
printf("The parent process ID is %d\n", getppid());
}
scanf("%d",&i); //so that program halts for user input
return 0;
}