#include<stdio.h>
int main()
{
    int i,j,k,n,f[30],recent[30],p[30],fn,pagefault=0,pos,found;
    printf("enter the no of pages : ");
    scanf("%d",&n);
    printf("enter the pages : \n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    printf("enter the no of frames : \n" );
    scanf("%d",&fn);
    printf("string \t frames : \n");
    for(i=0;i<fn;i++)
    {
        f[i]=-1;
        recent[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        found=0;
        for(j=0;j<fn;j++)
        {
            if(p[i]==f[j])
            {
                found=1;
                recent[j]=i;
                break;
            }
        }
        if(!found)
        {
            pos=0;
            for(j=0;j<fn;j++)
            {
                if(recent[j]<recent[pos])
                {
                    pos=j;
                }
            }
            f[pos]=p[i];
            recent[pos]=i;
            pagefault++;
        }
        printf("%d\t\t",p[i]);
        for(j=0;j<fn;j++)
        {
            if(f[j] != -1)
                printf("%d\t",f[j]);
            else
                printf("-\t");
        }
        printf("\n");
    }
    printf("\nPage Faults : %d",pagefault);
    return 0;

}
