/*finding the largest element in an array*/
#include<stdio.h>
int a[50],n,i;
int max;
int main()
{
    printf("enter n");
    scanf("%d",&n);
    printf("enter array elemnets");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }   
    printf("The largest value in the given array is %d", max);
}