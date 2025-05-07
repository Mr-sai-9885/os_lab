#include<stdio.h>
int main()
{
    int at[10],bt[10],ct[10],tat[10],wt[10],p[10],i,j,k,complete[10],count=0,min_bt,pos,time=0,n;
    float ttat=0,twt=0;
    printf("enter the no of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the process id : ");
        scanf("%d",&p[i]);
        printf("Enter p%d arrival time :",i+1);
        scanf("%d",&at[i]);
        printf("enter p%d Burst time : ",i+1);
        scanf("%d",&bt[i]);
        complete[i]=0;
    }
    while(count < n)
    {
        min_bt=9999;
        pos=-1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && complete[i]==0)
            {
                if(bt[i] < min_bt)
                {
                    min_bt=bt[i];
                    pos=i;
                }
            }
        }
        if(pos==-1)
        {
            time++;
        }
        else
        {
            ct[pos]=time+bt[pos];
            tat[pos]=ct[pos]-at[pos];
            wt[pos]=tat[pos]-bt[pos];
            ttat += tat[pos];
            twt += wt[pos];
            count++;
            time = ct[pos];
            complete[pos]=1;
        }
    }
    printf("At\tBt\tCt\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nTotal Turn Around time : %f \n Total waiting time : %f",ttat/n,twt/n);
    return 0;

}
