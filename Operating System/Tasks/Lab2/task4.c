#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
fork();
printf("The PID is %d\n", getpid());
return 0;
}