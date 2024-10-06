/*array linear saerch*/
#include<stdio.h>
int a[50],n,i;
int search;
int main()
{
    printf("enter n");
    scanf("%d",&n);
    printf("enter array elemnets");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }   
    printf("enter search elements");
    scanf("%d",&search);
    for(i=0;i<n;i++)
    {
        if(a[i]==search)
        {
            printf("element is found at %d",i);
        }
    }
}