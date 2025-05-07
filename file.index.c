#include<stdio.h>
#include<string.h>

struct
{
    char name[20];
    int nob,block[30];
}f[30];
int main()
{
    int i,j,n;
    char s[20];
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
        for(j=0;j<f[i].nob;j++)
        scanf("%d",&f[i].block[j]);
        printf("\n\n");
    }
    printf("enter the search file name : ");
    scanf("%s",&s);
    for(i=0;i<n;i++)
    {
        if((strcmp(s,f[i].name)) ==0)
            break;
    }
    if(i==n)
    {
                printf("File not found ");
    }
    else
    {
         printf("file_name\t starting_block\t no_of_block\t occupied_blocks\n");
         printf("%s\t%d\t",f[i].name,f[i].nob);
         for(j=0;j<f[i].nob;j++)
         {
            printf("%d, ",f[i].block[j]);
         }
    }



}

