//ʵ��n������Ϸ

#define _CRT_SECURE_NO_WARNINGS 1

#include"szq.h"

void menu()
{
	printf("*************************\n");
	printf("******1.������Ϸ********\n");
	printf("******0.�˳���Ϸ********\n");
	printf("*************************\n");
}
int  FinalJudge(char flag)
{
	if (flag == 'Y')
	{
		printf("���Ӯ\n");
		return 0;
	}
	else if (flag == 'C')
	{
		printf("����Ӯ\n");
		return 0;
	}
	else if (flag == 'P')
	{
		printf("ƽ��\n");
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
	assert(LONG_ture <= ROW);//���ԣ�long_ture���ɴ���ROW��COL��
	assert(LONG_ture <= COL);
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("���ڽ�����Ϸ...\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ��...\n");
			break;
		default:
			printf("�������,���������룡\n");
		}
	} while (input);
    system("pause");
	return 0;
}
