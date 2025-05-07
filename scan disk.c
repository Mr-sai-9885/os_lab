#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,size,rq[100],initial,thm=0,temp,move,index,j,i;
    printf("Enter the no of requests : ");
    scanf("%d",&n);
    printf("Enter the requests sequance :\n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("Enter the desk size : ");
    scanf("%d",&size);
    printf("Enter the initial value : ");
    scanf("%d",&initial);
    printf("Enter the direction 1 or 0 : ");
    scanf("%d",&move);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(rq[j]>rq[j+1])
            {
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(initial < rq[i])
        {
            index=i;
            break;
        }
    }
    if(move == 1)
    {
        for(i=index;i<n;i++)
        {
            thm =thm+ abs(rq[i]-initial);
            initial = rq[i];
        }
        thm = thm + abs(size-rq[i-1]-1);
        thm =thm + abs(size-1-0);
        initial = 0;
        for(i=0;i< index ; i++)
        {
            thm =thm+  abs(rq[i]-initial);
            initial = rq[i];
        }
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            thm =thm+  abs(rq[i]-initial);
            initial = rq[i];
        }
        thm =thm+  abs(rq[i+1]-0);
        thm =thm + abs(size-1-0);
        initial =size-1 ;
        for(i=index ;i<n;i++)
        {
            thm =thm +  abs(rq[i]-initial);
            initial = rq[i];
        }
    }
    printf(" Total head movements : %d", thm);
    return 0;
}
