//ʵ�ֺ�ŵ����
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int count=1;
int HanNuo(int n,char star,char bridge,char dest)
{
	if ( n>= 1)
	{
		HanNuo(n - 1, star, dest, bridge);
		//printf("\n��%d��\n", count);
		printf("��%d����%c----->%c\n", n, star, dest);
		//count++;
		HanNuo(n - 1, bridge, star, dest);
	}
	
}

int main()
{
	int n = 0;
	printf("���Ǽ��㺺ŵ����\n");
	scanf("%d", &n);
	HanNuo(n,'A','B','C');
	system("pause");
	return 0;
}
