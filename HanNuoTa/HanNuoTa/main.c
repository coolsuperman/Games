//实现汉诺塔；
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int count=1;
int HanNuo(int n,char star,char bridge,char dest)
{
	if ( n>= 1)
	{
		HanNuo(n - 1, star, dest, bridge);
		//printf("\n第%d步\n", count);
		printf("第%d个盘%c----->%c\n", n, star, dest);
		//count++;
		HanNuo(n - 1, bridge, star, dest);
	}
	
}

int main()
{
	int n = 0;
	printf("这是几层汉诺塔？\n");
	scanf("%d", &n);
	HanNuo(n,'A','B','C');
	system("pause");
	return 0;
}
