/*pragram to find even or odd*/
#include<stdio.h>
int main()
{
    int a;
    float b;
    printf("enter the number: ");
    scanf("%d",&a);
    b=a%2;
if(b==0)
    {
        printf("the given number is even");

    }
    else
    {
        printf("the given number is odd");
    }
}