//模拟实现计算器。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Sum(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a*b;
}
int Div(int a, int b)
{
	return a / b;
}

void menu()
{
	printf("*********************\n");
	printf("********1,加法*******\n");
	printf("********2,减法*******\n");
	printf("********3,乘法*******\n");
	printf("********4,除法*******\n");
	printf("********0.退出*******\n");
	printf("*********************\n");
}

int Calc(int(*fun)(int, int),int a,int b)
{
	return fun(a, b);
}

int main()
{
	int   a = 0, b = 0,fun=0;
	int(*ZhuanYiBiao[5])(int, int) = { 0,Sum,Sub,Mul,Div };//转移表
	do
	{
		menu();
		printf("请输入你想要输入功能\n");
		scanf("%d", &fun);
		printf("请输入要运算的数:>\n");
		scanf("%d%d", &a, &b);
		printf("结果是:>%d\n\n", Calc(ZhuanYiBiao[fun], a, b));
	} while (fun);
	system("pause");
	return 0;
}