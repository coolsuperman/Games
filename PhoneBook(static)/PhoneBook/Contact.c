#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

int menu()
{
	int input = 0;
	printf("\n");
	printf("***1,增加联系人***\n");
	printf("***2,删除联系人***\n");
	printf("***3,修改联系人***\n");
	printf("***4,查找联系人***\n");
	printf("***5,打印全部人***\n");
	printf("***6,按姓名排序***\n");
	printf("***7,清空联系人***\n");
	printf("***0,退出**********\n\n");
	while (1)
	{
		printf("请输入你的选择\n");
		scanf("%d", &input);
		if (input < 8 && input >= 0)
			return input;
		else
			printf("出入非法，重新输入!\n");
	}
}

void InitBook(PhoneBook* PhoneBook)
{
	PhoneBook->Size = 0;
	memset(PhoneBook->Book, 0, sizeof(PhoneBook->Book));
}

static int FindTarget(PhoneBook* PhoneBook, char*target)
{
	for (int i = 0; i < PhoneBook->Size; i++)
	{
		if (!(strcmp(PhoneBook->Book[i].name, target)))
		{
			return i;
		}
	}
	return -1;
}

void AddContact( PhoneBook* PhoneBook)
{
	printf("请输入你要添加的联系人\n");
	printf("姓名:\n");
	scanf("%s", PhoneBook->Book[PhoneBook->Size].name);
	printf("电话:\n");
	scanf("%s", PhoneBook->Book[PhoneBook->Size].tele);
	PhoneBook->Size++;
}

void DeletContact(PhoneBook* PhoneBook)
{
	char target[NAMELONGTH] = { 0 };
	printf("请输入你要删除的联系人\n");
	printf("姓名:\n");
	scanf("%s", &target);
	int FindResult = FindTarget(PhoneBook, target);
	if (FindResult != -1)
	{
		printf("删除成功！");
		for (int i = FindResult; i < PhoneBook->Size; i++)
		{
			if (i < (PhoneBook->Size - 1))
			{
				PhoneBook->Book[i] = PhoneBook->Book[i + 1];
			}
		}
		PhoneBook->Size--;
	}
	else
	{
		printf("你输入的名字我找不到==\n");
	}
}

void ChangeContact(PhoneBook* PhoneBook)
{
	char target[NAMELONGTH] = { 0 };
	int choice = 0;
	printf("请输入你要修改的联系人\n");
	printf("姓名:\n");
	scanf("%s", &target);
	int FindResult = FindTarget(PhoneBook, target);
	if (FindResult != -1)
	{
		printf("1.重命名 2.修改联系方式\n");
		scanf("%d", &choice);
		if (choice == 2)
		{
			printf("修改电话:\n");
			scanf("%s", PhoneBook->Book[FindResult].tele);
		}
		else if (choice == 1)
		{
			printf("重命名:\n");
			scanf("%s", PhoneBook->Book[FindResult].name);
		}
		else
		{
			printf("非法输入！\n");
		}
	}
	else
	{
		printf("你输入的名字我找不到==\n");
	}
}

void FindContact(PhoneBook* PhoneBook)
{
	char target[NAMELONGTH] = { 0 };
	printf("请输入你要查找的联系人\n");
	printf("姓名:\n");
	scanf("%s", &target);
	int FindResult = FindTarget(PhoneBook, target);
	if (FindResult != -1)
	{
		printf("%s：", PhoneBook->Book[FindResult].name);
		printf("%s\n", PhoneBook->Book[FindResult].tele);
	}
	else
	{
		printf("你输入的名字我找不到==\n");
	}
}

void PrintAll(PhoneBook* PhoneBook)
{
	for (int i = 0; i < PhoneBook->Size; i++)
	{
		printf("%s：",PhoneBook->Book[i].name);
		printf("%s\n",PhoneBook->Book[i].tele);
	}
}

void SortbyName(PhoneBook* PhoneBook)//快速排序，按从小到大，可英文&中文；
{
	PersonInfr temp;
	for (int i = 1; i < PhoneBook->Size; i++)
	{
		temp=PhoneBook->Book[i];
		int j = i - 1;
		while (j >= 0 && (strcmp(PhoneBook->Book[j].name, temp.name)>0))
		{
			PhoneBook->Book[j + 1] = PhoneBook->Book[j];
			j--;
		}
		PhoneBook->Book[j+1] = temp;
	}
	printf("排序成功!\n");
}

void CleanAll(PhoneBook* PhoneBook)
{
	int del = 0;
	printf("确定要删除全部联系人吗？0,是   1,否\n");
	scanf("%d", &del);
	if (!del)
	{
		PhoneBook->Size = 0;
		printf("电话簿已清空!\n");
	}
}

