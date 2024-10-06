/*area of triangle*/
#include<stdio.h>
int main()
{
    float b,h,area;
    int user_answer,yes,no;
    
    label1: printf("Enter the length of the base: ");
    scanf("%f",&b);
    printf("Enter the height of the triangle: ");
    scanf("%f",&h);
    area=0.5*b*h;
    printf("The area of the triangle is %f\n\n",area);
    
    printf("would you like to find the area of another triangle? \n1 for Yes \n2 for No\nP.S the commands are either 1 or 2 only\n");
    scanf("%d",&user_answer);
    
    if(user_answer==1)
    {
        goto label1;
    }   
}