#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char buf1[]="LAB";
char buf2[]="OS LINUX";
int main (void)

{

int fd;
if ((fd=creat("file.gol", 0666)) <0) {
printf("Creation error");
exit (1);
}

if (write(fd, buf1, sizeof(buf1)) < 0){
printf("Writing error");

exit(2);

}

if (lseek(fd, 4096, SEEK_SET) < 0){
printf("Positioning error");
exit(3);

}

if (write(fd, buf2, sizeof(buf2)) < 0)
{
printf(" Writing error");
exit(2);
}
}
