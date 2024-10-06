/*smalllest number in an array*/
#include<stdio.h>
int a[50],n,i;
int min;
int main()
{
    printf("enter n");
    scanf("%d",&n);
    printf("enter array elemnets");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    min=a[0];
    for(i=0;i<n;i++)
    {
        if(min>a[i])
        {
            min=a[i];
        }
    }   
    printf("The smallest value in the given array is %d", min);
}