/*write a program to print 1-n natural numbers w/o using loop*/
#include<stdio.h>
int main()
{
    int n,num=0;
    printf("enter the value of n: ");
    scanf("%d",&n);
    label1: 
    num=num+1;
    if(num<=n)
    {
        printf("%d\n",num);
        goto label1;
    }
}