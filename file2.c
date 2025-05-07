
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct file
{
char name[20];
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
char s[20];
struct block *temp;
printf("Enter no of files :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter file name %d :",i+1);
scanf("%s", f[i].name);
printf("Enter the no of blocks of file %d :",i+1);
scanf("%d",&f[i].nob);
f[i].sb= (struct block *)malloc(sizeof(struct block));
temp=f[i].sb;
printf("Enter no of blocks of the file:");
scanf("%d",&temp->bno);
temp->next=NULL;

for(j=1;j<f[i].nob;j++)

{
    temp->next = (struct block *)malloc(sizeof(struct block));
temp=temp->next;
scanf("%d", &temp->bno);

}
temp->next=NULL;
}
printf("\nEnter the file name to be searched -- ");
scanf("%s",s);
for(i=0;i<n;i++)
{
if(strcmp(s, f[i].name)==0)
break;
}
if(i==n)
printf("\nFile Not Found");
else
{
printf("\nFILE NAME START BLOCK NO OF BLOCKS BLOCKS OCCUPIED\n");
printf("\n%s\t\t%d\t",f[i].name,f[i].nob);
temp=f[i].sb;
for(j=0;j<f[i].nob;j++)
{
printf("%d->", temp->bno);
temp=temp->next;
}
}

return 0;
}
