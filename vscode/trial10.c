/*to find the roots of a given quadratic equation*/
#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,r1,r2,D;
    int user_answer;
    printf("we know that the standard form of a quadratic equation is ax^2+bx+c\n\n");
    label1: printf("enter the values of a, b and c\n");
    scanf("%f%f%f",&a,&b,&c);
    D=(b*b)-(4*a*c);
    if(D>-1)
    {
    r1=((-b)+sqrt(pow((b),(2))-4*a*c))/(2*a);
    r2=((-b)-sqrt(pow((b),(2))-4*a*c))/(2*a);
    printf("the roots of the equation are %f, %f\n\n",r1,r2);
    }
        else
        {
            printf("the determinant is less than zero hence the roots are imaginary\n\n");
        }

printf("would like to go over again?\n1 for yes\n2 to close\nP.S the commands are either 1 or 2 only\n\n");
scanf("%d",user_answer);
if(user_answer==1)
    {
        goto label1;
    }
}