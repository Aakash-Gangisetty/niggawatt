/*sum of N natural numbers*/
#include<stdio.h>
int main()
{
    int i,n,sum;
    printf("Enter the number n until you want the sum for,\n");
    scanf("%d",&n);
    for(i=1;1<=n;i++)
    {
        sum+=i;
    }
    printf("the sum of the n natural numbers is: %d",sum);
}