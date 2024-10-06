/*sum of the digits using tracing*/
#include<stdio.h>
int main()
{
    int n;
    int sum,rem;

    printf("Enter the value of n: ");
    scanf("%d",&n);

    while(n!=0)
    {
        rem=n%10;
        sum=sum+rem;
        n=n/10;
    }
    printf("the sum of the digits until given n is: %d",sum);
}