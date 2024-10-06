/*area of rectangle*/
#include<stdio.h>
int main()
{
    float a,b,area;
    printf("Enter the length of a side: ");
    scanf("%f",&a);
    printf("Enter the length of the adjacent side: ");
    scanf("%f",&b);
    area=a*b;
    printf("The area of the rectangle is %f",area);
}