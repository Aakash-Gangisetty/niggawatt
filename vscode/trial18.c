/*Armstrong number*/
#include<stdio.h>
int main()
{
    int n,r,s=0;
    printf("enter n: ");
    scanf("%d",&n);
    int t=n;
    while(n!=0)
    {
        r=n%10;
        s=s+r*r*r;
        n=n/10;
    }
    if (s==t)
    {
        printf("The given number is an armstrong number");
    }
    else 
    {
        printf("The given number is not an arstrong number");
    }
}