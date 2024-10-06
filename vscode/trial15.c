/*program for displaying multiplication table*/
#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter the number you want the table for,\n");
    scanf("%d",&n);

    for(i=1;i<=10;i++)
    {
        printf("%dx%d=%d\n",n,i,n*i);
    }
}