/*to find the factorial of a number*/
#include<stdio.h>
int main()
{
    int i,n,a;
    printf("Enter the number n until you want the factorial for,\n");
    scanf("%d",&n);
    for(i=1;1<=n;i--)
    {
        a*=i;
    }
    printf("the factotrial of the n natural numbers is: %d",a);
}