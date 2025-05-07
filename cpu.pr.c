#include<stdio.h>
int main()
{
    int at[10],bt[10],ct[10],tat[10],wt[10],pr[10],i,j,k,n,t;
    float ttat=0,twt=0;
    printf("enter the no of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter %d arrival time :",i+1);
        scanf("%d",&at[i]);
        printf("enter %d Burst time : ",i+1);
        scanf("%d",&bt[i]);
        printf("enter the priority :");
        scanf("%d",&pr[i]);
    }

    //sorting
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j] || (pr[i] == pr[j] && at[i]>at[j]))
            {
                t=pr[i];
                pr[i]=pr[j];
                pr[j]=t;

                t=at[i];
                at[i]=at[j];
                at[j]=t;

                t=bt[i];
                bt[i]=bt[j];
                bt[j]=t;
            }
        }
    }

    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++)
    {
        if(at[i]>ct[i-1] )
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
    printf("arrival_time   Burst_time   Completion_time        TAT       waiting_time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nTotal Turn Around time : %f \n Total waiting time : %f",ttat/n,twt/n);
    return 0;
}
