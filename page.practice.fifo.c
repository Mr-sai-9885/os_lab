#include<stdio.h>

int main()
{
    int i,j,k,n,a[50],f[50],fn,avail,count=0;
    printf("enter the no of pages : ");
    scanf("%d",&n);
    printf("enter the pages : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the no of frames : ");
    scanf("%d",&fn);
    for(i=0;i<fn;i++)
        f[i]=-1;
    printf("  ref string \t\t frames \n");
    j=0;
    for(i=0;i<n;i++)
    {
        printf("%d\t\t\t",a[i]);
        avail=0;
        for(k=0;k<fn;k++)
            if(f[k]==a[i])
            avail=1;
        if(avail==0)
        {
            f[j]=a[i];
            j=(j+1)%fn;
            count++;
            for(k=0;k<fn;k++)
            {
                printf("%d\t",f[k]);
            }
        }
        printf("\n\n");
    }
    printf("page fault is :%d",count);
    return 0;
}
