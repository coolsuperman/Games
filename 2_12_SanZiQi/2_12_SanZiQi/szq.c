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
	memset(arr, ' ', rows*cols);   //void *memset(void *s, int ch, size_t n);��������:��s�е�ǰλ�ú����n���ֽ�,�� ch �滻������ s ;��������һ���ڴ�������ĳ��������ֵ;
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
		printf("\n�����:\n����������>");
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
				printf("\n��λ����������,����������!\n");
			}
		}
		else
		{
			printf("\n����Ƿ����꣡����������.\n");
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
	printf("\n������:\n");
	arr[x][y] = 'C';
}

void ComputerMov_smart()
{
	//������Ұ��ӵ��Ժ���
	//Χ�£���ȡ��������ӵ���а˷���ʶ�𣬸��ݲ�ͬ����ɼ������������Ӽ��Բ�ͬȨ�صó���в��ߵ�������·���ڴ���·�ϵİ�������ȡ��Χ�˷��к��ӵ�λ���������ӣ����������.
	//�Ѷȵ������������İ���������ͬ��Ȩֵ���Ȩֵ��ͬʱ�������������

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
					for (n = 1; n <= LONG; n++)//������
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
					for (n = 1; n <= LONG; n++)//������
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
					for (n = 1; n <= LONG; n++)//������
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
					for (n = 1; n <= LONG; n++)//������
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
					for (n = 1; n <= LONG; n++)//��������
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
					for (n = 1; n <= LONG; n++)//��������
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
					for (n = 1; n <= LONG; n++)//��������
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
					for (n = 1; n <= LONG; n++)//��������
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
					//�Ӱ˸�����ʼץȡԪ������ͬ�Ҳ�Ϊ�ո����������һ��
					if (count1 == LONG || count2 == LONG || count3 == LONG || count4 == LONG || count5 == LONG || count6 == LONG || count7 == LONG || count8 == LONG)
					{
						return arr[i][j];
					}
				}
			}
		}

}//�˷���ʶ��ʵ�������ƻ�ʤ�����������ӵ�������