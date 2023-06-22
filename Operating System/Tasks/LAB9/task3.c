#include <stdio.h>
#include <stdlib.h>

int main()

{
int num;
FILE *fptr;

if ((fptr = fopen("File1.txt","r")) == NULL)
{
printf ("Error in opening file!");
exit (1);
}
fscanf (fptr, "%d", &num) ;

printf ("Value of n = %d \n ",num);
fclose (fptr) ;

}