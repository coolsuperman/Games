//实现n子棋游戏

#define _CRT_SECURE_NO_WARNINGS 1

#include"szq.h"

void menu()
{
	printf("*************************\n");
	printf("******1.进入游戏********\n");
	printf("******0.退出游戏********\n");
	printf("*************************\n");
}
int  FinalJudge(char flag)
{
	if (flag == 'Y')
	{
		printf("玩家赢\n");
		return 0;
	}
	else if (flag == 'C')
	{
		printf("电脑赢\n");
		return 0;
	}
	else if (flag == 'P')
	{
		printf("平局\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

void game()
{
	int Break = 0;
	char flag;
	char arr[ROWS][COLS];
	InitBoard(arr, ROWS, COLS);
	DisplayBoard(arr, ROW, COL);
	do
	{
		PlayerMov(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		flag = JudgeWin(arr, ROW, COL);
		Break = FinalJudge(flag);
		ComputerMov(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		flag = JudgeWin(arr, ROW, COL);
		Break = FinalJudge(flag);
	} while (Break);
}

int main()
{
	assert(LONG_ture <= ROW);//断言：long_ture不可大于ROW与COL；
	assert(LONG_ture <= COL);
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("正在进入游戏...\n");
			game();
			break;
		case 0:
			printf("退出游戏中...\n");
			break;
		default:
			printf("输入错误,请重新输入！\n");
		}
	} while (input);
    system("pause");
	return 0;
}
