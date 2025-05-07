#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
    char name[30];
    int nob;
    struct block
    {
        int bno;
        struct block *next;

    }*sb;
}f[30];
int main()
{
    int i,j,n;
    char s[30];
    struct block *temp;
    printf("Enter the no of blocks : ");
    scanf("%d",&n);
    printf("enter the %d files : ",n);
    for(i=0;i<n;i++)
    {
        printf("file name : ");
        scanf("%s",&f[i].name);
        printf("enter the no of block : " );
        scanf("%d",&f[i].nob);
        printf("Enter the blocks : ");
        f[i].sb = (struct block *)malloc(sizeof(struct block));
        temp=f[i].sb;
        scanf("%d",&temp->bno);
        temp->next=NULL;
        for(j=1;j<f[i].nob;j++)
        {
            temp->next = (struct block*)malloc(sizeof(struct block));
            temp=temp->next;
            scanf("%d",&temp->bno);
        }
        temp->next=NULL;

    }
    printf("Enter the search file : ");
    scanf("%s",&s);
    for(i=0;i<n;i++)
    {
        if(strcmp(s,f[i].name)==0)
            break;
    }
    if(i==n)
        printf("File not Found\n");
    else
    {
        printf("file name\t noofblocks\t occupiedblocks\n");
        printf("%s\t%d\t",f[i].name,f[i].nob);
        temp=f[i].sb;
        for(j=0;j<f[i].nob;j++)
        {
            printf("%d->",temp->bno);
            temp=temp->next;
        }
    }
    return 0;
}
