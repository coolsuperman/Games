//////实现完全版扫雷；
//////思路：这里重点只提如何实现点一下扩散一片的效果：这个效果实现于Consecutive_show()函数，核心思想是在传入一个合法坐标(为空且周围无雷)后，以此坐标为中心向上下左右四个
//方向抓取距离为1的相邻格子再以这些格子为核心再次抓取距离唯一的相邻格子，循环往复达到覆盖整个棋盘的目的，因为步骤的相似性，我在这里使用了递归，当检测到周围存在地雷时，
//立刻将自身标记为周围雷的个数(CountBom()函数)，在这里为了避免重复查找，我将每一个曾作为核心的格子都替换为字符空格，在接下来的查找过程中一旦检测到空格便不做处理直接跳过。
//////Debug log：
//***使用递归时添加限制条件不充分，导致程序经常性栈溢出！
//***频繁使用for以及while导致层次太深无法及时跳出，后修改了整个函数结构。
/////存在问题：
//使用的if语句过多可能会导致性能下降。
#define _CRT_SECURE_NO_WARNINGS 1

#include"SL.h"

void game()
{
	char ture[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(ture, ROWS, COLS, '0');
	SetBom(ture, ROW, COL);
	InitBoard(show, ROWS, COLS, '*');
	PrintBoard(ture, ROW, COL);
	PrintBoard(show, ROW, COL);
    PyrMov(ture, show,ROW, COL);
}

void menu()
{
	printf("************************\n");
	printf("******1,开始游戏********\n");
	printf("******0,退出游戏********\n");
	printf("************************\n");

}

int main()
{
	assert(BOM < ROW*COL);
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
		}
	}while (input);
	system("pause");
	return 0;
}