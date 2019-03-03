#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

int menu()
{
	int input = 0;
	printf("\n");
	printf("***1,������ϵ��***\n");
	printf("***2,ɾ����ϵ��***\n");
	printf("***3,�޸���ϵ��***\n");
	printf("***4,������ϵ��***\n");
	printf("***5,��ӡȫ����***\n");
	printf("***6,����������***\n");
	printf("***7,�����ϵ��***\n");
	printf("***0,�˳�**********\n\n");
	while (1)
	{
		printf("���������ѡ��\n");
		scanf("%d", &input);
		if (input < 8 && input >= 0)
			return input;
		else
			printf("����Ƿ�����������!\n");
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
	printf("��������Ҫ��ӵ���ϵ��\n");
	printf("����:\n");
	scanf("%s", PhoneBook->Book[PhoneBook->Size].name);
	printf("�绰:\n");
	scanf("%s", PhoneBook->Book[PhoneBook->Size].tele);
	PhoneBook->Size++;
}

void DeletContact(PhoneBook* PhoneBook)
{
	char target[NAMELONGTH] = { 0 };
	printf("��������Ҫɾ������ϵ��\n");
	printf("����:\n");
	scanf("%s", &target);
	int FindResult = FindTarget(PhoneBook, target);
	if (FindResult != -1)
	{
		printf("ɾ���ɹ���");
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
		printf("��������������Ҳ���==\n");
	}
}

void ChangeContact(PhoneBook* PhoneBook)
{
	char target[NAMELONGTH] = { 0 };
	int choice = 0;
	printf("��������Ҫ�޸ĵ���ϵ��\n");
	printf("����:\n");
	scanf("%s", &target);
	int FindResult = FindTarget(PhoneBook, target);
	if (FindResult != -1)
	{
		printf("1.������ 2.�޸���ϵ��ʽ\n");
		scanf("%d", &choice);
		if (choice == 2)
		{
			printf("�޸ĵ绰:\n");
			scanf("%s", PhoneBook->Book[FindResult].tele);
		}
		else if (choice == 1)
		{
			printf("������:\n");
			scanf("%s", PhoneBook->Book[FindResult].name);
		}
		else
		{
			printf("�Ƿ����룡\n");
		}
	}
	else
	{
		printf("��������������Ҳ���==\n");
	}
}

void FindContact(PhoneBook* PhoneBook)
{
	char target[NAMELONGTH] = { 0 };
	printf("��������Ҫ���ҵ���ϵ��\n");
	printf("����:\n");
	scanf("%s", &target);
	int FindResult = FindTarget(PhoneBook, target);
	if (FindResult != -1)
	{
		printf("%s��", PhoneBook->Book[FindResult].name);
		printf("%s\n", PhoneBook->Book[FindResult].tele);
	}
	else
	{
		printf("��������������Ҳ���==\n");
	}
}

void PrintAll(PhoneBook* PhoneBook)
{
	for (int i = 0; i < PhoneBook->Size; i++)
	{
		printf("%s��",PhoneBook->Book[i].name);
		printf("%s\n",PhoneBook->Book[i].tele);
	}
}

void SortbyName(PhoneBook* PhoneBook)//�������򣬰���С���󣬿�Ӣ��&���ģ�
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
	printf("����ɹ�!\n");
}

void CleanAll(PhoneBook* PhoneBook)
{
	int del = 0;
	printf("ȷ��Ҫɾ��ȫ����ϵ����0,��   1,��\n");
	scanf("%d", &del);
	if (!del)
	{
		PhoneBook->Size = 0;
		printf("�绰�������!\n");
	}
}

