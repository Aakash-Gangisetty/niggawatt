#include<stdio.h>
int add();
int main()
{
	printf("sum is %d",add());
}
int add()
{
	int a,b;
	printf("enter a,b");
	scanf("%d%d",&a,&b);
	return a+b;
}
