/*Converting binary to decimal and vice-versa*/
#include<stdio.h>
int main()
{
    int dec,bin;
    int buffer1,buffer2;
    int n,i; //for switch case 1.
    int user_answer; //for looping the program.
    int count;
    char output[64];

    label2: printf("What do you want to convert from?\n1 for decimal\n2 for binary\n");
    scanf("%d",&buffer1);

    switch(buffer1)
    {
        case 1:
        printf("Enter the decimal value: ");
        scanf("%d",&dec);
        printf("\n");  //for the sake of neatness in output.
        label1: n=dec%2;
        if(n==0)
        {
            printf("0");
        }
        else 
        {
            printf("1");
        }
        i=dec/2;
        if(i>=1)
        {
            dec = i;
            goto label1;
        }
        else
        {
            printf(" is the given decimal in binary form");
        }
        if(dec=0)
        {
            printf("0 is the given decimal in binary form");
        }
        break;
        


        case 2:
        printf("under development please get out");
        break;
    }

    printf("\n\nwould you like to go again?\n1 for yes\n2 to close\n");
    scanf("%d",&user_answer);
    if(user_answer==1)
    {
        goto label2;
    }
}