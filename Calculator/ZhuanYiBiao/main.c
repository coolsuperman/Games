//ģ��ʵ�ּ�������
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
	printf("********1,�ӷ�*******\n");
	printf("********2,����*******\n");
	printf("********3,�˷�*******\n");
	printf("********4,����*******\n");
	printf("********0.�˳�*******\n");
	printf("*********************\n");
}

int Calc(int(*fun)(int, int),int a,int b)
{
	return fun(a, b);
}

int main()
{
	int   a = 0, b = 0,fun=0;
	int(*ZhuanYiBiao[5])(int, int) = { 0,Sum,Sub,Mul,Div };//ת�Ʊ�
	do
	{
		menu();
		printf("����������Ҫ���빦��\n");
		scanf("%d", &fun);
		printf("������Ҫ�������:>\n");
		scanf("%d%d", &a, &b);
		printf("�����:>%d\n\n", Calc(ZhuanYiBiao[fun], a, b));
	} while (fun);
	system("pause");
	return 0;
}