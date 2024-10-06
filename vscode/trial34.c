/*finding the power of the numbers using recursing functions*/
#include<stdio.h>
int f(int num);
int main()
{
    int n;
    printf("enter the number you want to find the factorial for: ");
    scanf("%d",&n);
    printf("%d",f(n));
}
int f(int num)
{
    if(num==0)
    {
        return 1;
    }
    else
    {
        return num*f(num-1);
    }
}
