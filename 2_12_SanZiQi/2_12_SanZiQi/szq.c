#define _CRT_SECURE_NO_WARNINGS 1

#include"szq.h"

static int Full(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = row*col;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (arr[i][j] != ' ')
			{
				count--;
			}
		}
	}
	if (count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void InitBoard(char arr[ROWS][COLS],int rows,int cols)
{
	/*int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}*/
	memset(arr, ' ', rows*cols);   //void *memset(void *s, int ch, size_t n);函数解释:将s中当前位置后面的n个字节,用 ch 替换并返回 s ;作用是在一段内存块中填充某个给定的值;
}


void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <=row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j <= col - 1)
			{
				printf("|");
			}
			else
			{
				printf("\n");
			}
		}
		for (j = 1; j <=col; j++)
		{
			printf("---");
			if (j <=col- 1)
			{
				printf("|");
			}
			else
			{
				printf("\n");
			}
		}
	}
}

void PlayerMov(char arr[ROWS][COLS], int row, int col)
{
	int a = 0;
	int b = 0;
	while (1)
	{
		printf("\n玩家走:\n请输入坐标>");
		scanf("%d%d", &a, &b);
		if (a > 0 && a <= row && b > 0 && b <= col)
		{
			if (arr[a ][b] == ' ')
			{
				arr[a][b] = 'Y';
				break;
			}
			else
			{
				printf("\n该位置已有棋子,请重新输入!\n");
			}
		}
		else
		{
			printf("\n输入非法坐标！请重新输入.\n");
		}
	}
}

void ComputerMov(char arr[ROWS][COLS], int row, int col)
{
	int x = (rand() % row) + 1;
	int y = (rand() % col) + 1;
	while (arr[x][y] != ' ')
	{
		x =(rand() % row)+1;
		y = (rand() % col)+1;
	}
	printf("\n电脑走:\n");
	arr[x][y] = 'C';
}

void ComputerMov_smart()
{
	//假设玩家白子电脑黑子
	//围堵：采取对玩家落子点进行八方向识别，根据不同方向采集到的相连白子加以不同权重得出威胁最高的那条线路，在此线路上的白子两端取周围八方有黑子的位置有限落子；若无则随机.
	//难度调整：调整上文白子数量不同的权值差，当权值相同时，电脑随机落子

}

char JudgeWin(char arr[ROWS][COLS], int row, int col)
{
	int count1= 0;
	int count2= 0;
	int count3= 0;
	int count4= 0;
	int count5 = 0;
	int count6= 0;
	int count7= 0;
	int count8= 0;
	int i = 0;
	int j = 0;
	int n = 0;
	int falg = 0;
	falg = Full(arr,row,col);
	if (falg == 1)
	{
		return 'P';
	}
	for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (arr[i][j] != ' ')
				{
					for (n = 1; n <= LONG; n++)//方向下
					{
						if (arr[i + n][j] == arr[i][j])
						{
							count1++;
						}
						else
						{
							count1 = 0;
							break;
						}
					}
					for (n = 1; n <= LONG; n++)//方向上
					{
						if (arr[i - n][j] == arr[i][j])
						{
							count2++;
						}
						else
						{
							count2 = 0;
							break;
						}
					}
					for (n = 1; n <= LONG; n++)//方向左
					{
						if (arr[i][j - n] == arr[i][j])
						{
							count3++;
						}
						else
						{
							count3 = 0;
							break;
						}
					}
					for (n = 1; n <= LONG; n++)//方向右
					{
						if (arr[i][j + n] == arr[i][j])
						{
							count4++;
						}
						else
						{
							count4 = 0;
							break;
						}
					}
					for (n = 1; n <= LONG; n++)//方向左上
					{
						if (arr[i - n][j - n] == arr[i][j])
						{
							count5++;
						}
						else
						{
							count5 = 0;
							break;
						}
					}
					for (n = 1; n <= LONG; n++)//方向右上
					{
						if (arr[i - n][j + n] == arr[i][j])
						{
							count6++;
						}
						else
						{
							count6 = 0;
							break;
						}
					}
					for (n = 1; n <= LONG; n++)//方向左下
					{
						if (arr[i + n][j - n] == arr[i][j])
						{
							count7++;
						}
						else
						{
							count7 = 0;
							break;
						}
					}
					for (n = 1; n <= LONG; n++)//方向右下
					{
						if (arr[i + n][j + n] == arr[i][j])
						{
							count8++;
						}
						else
						{
							count8 = 0;
							break;
						}
					}
					//从八个方向开始抓取元素若相同且不为空格则计数器加一；
					if (count1 == LONG || count2 == LONG || count3 == LONG || count4 == LONG || count5 == LONG || count6 == LONG || count7 == LONG || count8 == LONG)
					{
						return arr[i][j];
					}
				}
			}
		}

}//八方向识别实现灵活控制获胜所需相连棋子的数量；