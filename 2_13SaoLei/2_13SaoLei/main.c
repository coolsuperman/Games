//////ʵ����ȫ��ɨ�ף�
//////˼·�������ص�ֻ�����ʵ�ֵ�һ����ɢһƬ��Ч�������Ч��ʵ����Consecutive_show()����������˼�����ڴ���һ���Ϸ�����(Ϊ������Χ����)���Դ�����Ϊ���������������ĸ�
//����ץȡ����Ϊ1�����ڸ���������Щ����Ϊ�����ٴ�ץȡ����Ψһ�����ڸ��ӣ�ѭ�������ﵽ�����������̵�Ŀ�ģ���Ϊ����������ԣ���������ʹ���˵ݹ飬����⵽��Χ���ڵ���ʱ��
//���̽�������Ϊ��Χ�׵ĸ���(CountBom()����)��������Ϊ�˱����ظ����ң��ҽ�ÿһ������Ϊ���ĵĸ��Ӷ��滻Ϊ�ַ��ո��ڽ������Ĳ��ҹ�����һ����⵽�ո�㲻������ֱ��������
//////Debug log��
//***ʹ�õݹ�ʱ���������������֣����³��򾭳���ջ�����
//***Ƶ��ʹ��for�Լ�while���²��̫���޷���ʱ���������޸������������ṹ��
/////�������⣺
//ʹ�õ�if��������ܻᵼ�������½���
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
	printf("******1,��ʼ��Ϸ********\n");
	printf("******0,�˳���Ϸ********\n");
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
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
		}
	}while (input);
	system("pause");
	return 0;
}