#include<stdio.h>
int main()
{
    int at[10],bt[10],ct[10],tat[10],wt[10],i,j,k;
    float ttat=0,twt=0,n;
    printf("enter the no of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter %d arrival time :",i+1);
        scanf("%d",&at[i]);
        printf("enter %d Burst time : ",i+1);
        scanf("%d",&bt[i]);
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++)
    {
        if(ct[i-1]<at[i])
            ct[i]=at[i]+bt[i];
        else
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        ttat += tat[i];
        twt += wt[i];
    }
    printf("arrival_time   Burst_time   Completion_time        TAT       waiting_time\n ");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nTotal Turn Around time : %d \n Total waiting time : %d",ttat/n,twt/n);
    return 0;
}
