#include<stdio.h>

int isfound(int f[],int fn,int p)
{
    int i;
    for(i=0;i<fn;i++)
    {
        if(f[i]==p)
            return 1;
    }
    return 0;
}
int main()
{
    int p[30],f[30],replace,pf=0,n,fn,i,j;
    printf("enter the no of pages : ");
    scanf("%d",&n);
    printf("enter the pages :\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("enter the frames size : ");
    scanf("%d",&fn);
    for(i=0;i<fn;i++)
        f[i]=-1;
    printf("string \t frames : \n");
    for(i=0;i<n;i++)
    {
        if(!(isfound(f,fn,p[i])))
        {
            if(i<fn)
                replace = i;
            else
                replace = findoptimal(p,n,f,fn,i+1);
            f[replace]=p[i];
            pf++;
        }

        printf("%d\t\t",p[i]);
        for(j=0;j<fn;j++)
        {
            if(f[j] != -1)
                printf("%d\t",f[j]);
            else
                printf("-\t");
        }
        printf("\n\n");
    }
    printf(" page fault id : %d",pf);
}


int findoptimal(int p[],int n, int f[],int fn , int current)
{
    int future=current,i,j;
    int    replace = -1;
    for(i=0;i<fn;i++)
    {
        for(j=current;j<n;j++)
        {
            if(f[i]==p[j])
            {
                if(j>future)
                {
                    future=j;
                    replace=i;
                }
                break;
            }
        }
        if(j == n ) return i;
    }
    return (replace == -1 )? 0: replace;
}
