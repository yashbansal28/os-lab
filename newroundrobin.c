#include<stdio.h>
int main()
{
    int i,j,n,tq;
    int at[n],bt[n],ct[n],rt[n],wt[n],tat[n];
    printf("Enter the no of processes\n");
    scanf("%d",&n);
    printf("Enter the arrival times");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);
    printf("Enter the burst times");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);
    printf("Enter time quantum");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
    {
        rt[i]=bt[i];
        ct[i]=0;
        wt[i]=0;
        tat[i]=0;
    }
    int cp=0;
    int currenttime=0;
    while(cp<n)
    {
        for(i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
               int et=(rt[i]<tq)?rt[i]:tq;
               rt[i]=rt[i]-et;
               currenttime=currenttime+et;
               ct[i]=currenttime;
               if(rt[i]==0)
               {
                   tat[i]=ct[i]-at[i];
                   wt[i]=tat[i]-bt[i];
                   cp++;
               }
            }
        }
    }
    printf("\nRound Robin Scheduling:\n");
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    float atat = 0, awt = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, at[i], bt[i],
               ct[i], tat[i], wt[i]);
        atat += tat[i];
        awt += wt[i];
    }

    atat /= n;
    awt /= n;

    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);
    return 0;
}
