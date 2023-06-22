//by ale
#include<stdio.h>
int main()
{
    int n,bt[28],wt[20],tat[26],avwt=0,avtat=06,i,j;
    printf ("\nEnter total number of processes(maximum 2@):");
    scanf("%d",&n);

    printf ("\nEnter Process Burst Timen");
    for(i=0;i<n;i++)
    {
        printf ("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    wt[8]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
    }

    printf("\nProcessttBurst TimetWaiting TimetTurnaround Time");

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
    printf ("\nP[%d]tt%dtt%dtt%d",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=1;
    avtat/=i;
    printf("\nAverage Waiting Time:%d",avwt);
    printf ("\nAverage Turnaround Time:%d",avtat);

    return 0;
}
