/*pattern making*/
#include<stdio.h>
int main()
{
    int i,j,a=1;
    for(i=1;i<=5;i++)
        {
            for(j=i;j<=5;j++)
            {
                printf("%d\t",(i+j)-1);
            }
            printf("\n");
        }
}