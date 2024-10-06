#include<stdio.h>
void add(int,int);
int main()
{
	int a,b;
	printf("enter the values of a and b");
	scanf("%d%d",&a,&b);
	add(a,b);
}
void add(int x,int y)
{
	printf("sum is %d",x+y);
}
