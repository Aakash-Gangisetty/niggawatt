/*compound interest*/
#include<stdio.h>
#include<math.h>
int main()
{
    float A,p,r,n,t;
    int user_answer,yes,no;
    label1: printf("Enter the Principle amount: ");
    scanf("%f",&p);
    printf("Enter the Annual interest rate: ");
    scanf("%f",&r);
    printf("Enter the number of times the money is compunded per year: ");
    scanf("%f",&n);
    printf("Enter the amount of years the money is invested for: ");
    scanf("%f",&t);
    A=p*pow((1+r/n),(n*t));
    printf("The compunded interest is: %f\n\n",A);

    printf("would you like to do another calculation? \n1 for Yes \n2 to close\nP.S the commands are either 1 or 2 only\n\n");
    scanf("%d",&user_answer);
    
    if(user_answer==1)
    {
        goto label1;
    }   
}