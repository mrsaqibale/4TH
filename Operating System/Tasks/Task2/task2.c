#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>


int main(){
int i;
printf("Process ID is %d\n", getpid());
for(i=0; i<=400;i++){
printf("i is %d\n", i);
}
return 0;
}