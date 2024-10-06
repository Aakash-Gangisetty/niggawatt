/*to check if given value n is a prime number or not*/
#include<stdio.h>
int main()
{
    int n,i,flag=0;
    printf("enter a numberto check if it is a prime number: ");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%1==0)
        {
            flag++;
        }
    }
    if(flag==0)
    {
        printf("the given number is a prime number");
    }
        else
        {
            printf("the given number is not a prime number");
        }
        
}