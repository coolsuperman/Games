//ʵ��һ���绰����ʹ�ã����ӣ�ɾ�����޸ģ����ң���ӡȫ��������������������м�¼
#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

int main()
{
	printf("%s","ͨ��¼:\n");
	PhoneBook FirstBook;
	InitBook(&FirstBook);
	Load(&FirstBook);
	fun ChooseFun[10] = { AddContact,DeletContact,ChangeContact,FindContact,PrintAll,SortbyName,CleanAll};
	int choice = 0;
	do
	{
		choice = menu();
		if (choice)
		{
			ChooseFun[choice - 1](&FirstBook);
			printf("\n");
			ChooseFun[4](&FirstBook);
		}
	} while (choice);
	Save(&FirstBook);
	free(FirstBook.Book);
	system("pause");
	return 0;
}
