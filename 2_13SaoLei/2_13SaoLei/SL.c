#define _CRT_SECURE_NO_WARNINGS 1

#include "SL.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols,char want)
{
	memset(arr, want, rows*cols);
}

void PrintBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("  ");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d  ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetBom(char ture[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = BOM;
	while (count)
	{
		x = (rand() % row) + 1;
		y = (rand() % row) + 1;
		if (ture[x][y] == '0')
		{
			ture[x][y] = '1';
			count--;
		}
	}
}

static void SetBomforFrist_PyrMov(char ture[ROWS][COLS],int x,int y)
{
	int count = 1;
	while (count)
	{
		x = (rand() % ROW) + 1;
		y = (rand() % COL) + 1;
		if (ture[x][y] == '0')
		{
			ture[x][y] = '1';
			count--;
		}
	}
}

static int CountBom(char ture[ROWS][COLS], int x, int y )
{
	int count = 0;
	//return (ture[x-1][y] + ture[x-1][y-1] + ture[x][y-1] + ture[x+1][y-1] + ture[x+1][y] + ture[x+1][y+1] + ture[x][y+1] + ture[x-1][y+1]) % '0';
	if (ture[x - 1][y] != ' ')
	{
		count +=(ture[x-1][y]-'0');
	}
	if (ture[x - 1][y-1] != ' ')
	{
		count += (ture[x - 1][y-1] - '0');
	}
	if (ture[x][y-1] != ' ')
	{
		count += (ture[x][y-1] - '0');
	}
	if (ture[x+1][y-1] != ' ')
	{
		count += (ture[x+1][y-1] - '0');
	}
	if (ture[x+1][y] != ' ')
	{
		count += (ture[x+1][y] - '0');
	}
	if (ture[x+1][y+1] != ' ')
	{
		count += (ture[x+1][y+1] - '0');
	}
	if (ture[x][y+1] != ' ')
	{
		count += (ture[x][y+1] - '0');
	}
	if (ture[x - 1][y+1] != ' ')
	{
		count += (ture[x - 1][y+1] - '0');
	}
	return count;
}

static void Consecutive_show(char ture[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int blank = 0;
	//blank = CountBom(ture, x, y) % 13;//'='-'0'的asc码值是13所以即使检测到' ='返回的值必然是'1'的个数加上13的倍数，blank得到的就是不含已检测过安全格的其他格得到的结果//不成熟会损失数据。
	blank = CountBom(ture, x, y);
	if (blank == 0)
	{
		ture[x][y] = ' ';
		show[x][y] = ' ';
		if (x > 0 && x <= ROW && y>0 && y <= COL )
		{
			if (ture[x - 1][y] != ' ')
			{
				Consecutive_show(ture, show, x - 1, y);//上
			}
			if (ture[x][y-1] != ' ')
			{
				Consecutive_show(ture, show, x , y-1);//左
			}
			if (ture[x+1][y] != ' ')
			{
				Consecutive_show(ture, show, x +1, y);//下
			}
			if (ture[x][y+1] != ' ')
			{
				Consecutive_show(ture, show, x, y+1);//右
			}
		}
	}
	else
	{
		show[x][y] = blank + '0';
	}
}

void PyrMov(char ture[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int flag = 1;
	int x = 0;
	int y = 0;
	int count= 0;
	int i = 0;
	int j = 0;
	int judge_Frist = 1;
	while (flag)
	{
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (show[i][j] == '*')
				{
					count++;
				}
			}
		}
		if (count >BOM)
		{
			printf("请输入坐标:>");
			scanf("%d%d", &x, &y);
			if (x > 0 && x <= row && y > 0 && y <= col)
			{
				/*	if (count <(row*col-BOM-1))
				{*/
				//PrintBoard(ture, ROW, COL);

				if (ture[x][y] == '1' && judge_Frist == 1)//为了提升玩家的游戏体验，第一次走如果踩到雷，调用SetBomforFrist_PyrMov()将这颗雷转移到其他地方；
				{
					judge_Frist = 0;
					ture[x][y] = '0';
					SetBomforFrist_PyrMov(ture, x, y);
					Consecutive_show(ture, show, x, y);
					PrintBoard(ture, ROW, COL);
				}
				else if (ture[x][y] == '1')
				{
					printf("踩到雷了，GameOver！\n\n");
					flag = 0;
					PrintBoard(ture, ROW, COL);
				}
				else
				{
					judge_Frist = 0;
					//show[x][y] = CountBom(ture, x, y) + '0';
					Consecutive_show(ture, show, x, y);
					PrintBoard(show, ROW, COL);
				}
				//count++;
				//}
				/*	else
				{
				printf("扫雷成功！厉害!\n\n");
				flag = 0;
				}*/
			}
			else
			{
				printf("输入非法坐标，请重新输入!/n");
			}
			count = 0;
		}
		else
		{
			printf("扫雷成功！厉害!\n\n");
			flag = 0;
		}
	}
}

