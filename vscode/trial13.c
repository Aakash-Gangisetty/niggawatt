/*positive or negitive assignment*/
#include<stdio.h>
int main()
{
    int num;
    printf("enter the number\n");
    scanf("%d",&num);

    switch(num)
    {
        case >0:
        printf("the number is positive");
        break;

        case <0:
        printf("the number is negitive");
        break;

        case 0:
        printf("the number is qual to zero");
        break;
    }
}