/*to find day name*/
#include<stdio.h>
int main()
{
    int day;
    printf("enter a number between 1 and 7\n");
    scanf("%d",&day);

    switch(day)
    {
        case 1:
        printf("Its monday");
        break;
        
        case 2:
        printf("It's tuesday");
        break;

        case 3:
        printf("Its wednesday");
        break;

        case 4:
        printf("Its thursday");
        break;

        case 5:
        printf("Its friday");
        break;

        case 6:
        printf("Its saturday");
        break;

        case 7:
        printf("Its sunday");
        break;
    }    

}