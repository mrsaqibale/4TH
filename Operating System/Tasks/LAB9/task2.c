#include <stdlib.h>
#include <stdio.h>

int main()
{
int num;
FILE *fptr;
fptr = fopen("File1.txt","w");

if (fptr == NULL)
{
printf ("Error");
exit (1);
}

printf ("enter num");
scanf ("%d", &num) ;

fprintf (fptr, "%d", num);

fclose (fptr);
}