/*to find the qreatest of the three numbers*/
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    printf("enter the value of a: ");
    scanf("%d",&a);
    printf("enter the value of b: ");
    scanf("%d",&b);
    printf("enter the value of c: ");
    scanf("%d",&c);

    if(a>b&&a>c)
    {
        printf("%d is the greatest number",a);
        
    }
    else if(b>c&&b>a)
    {
        printf("%d is the greatest number",b);
    }
    else if(c>b&&c>a)
    {
        printf("%d is the greatest number",c);
    }
    else if(a==b==c)
    {
        printf("all the numbers are equal");
    }
}

