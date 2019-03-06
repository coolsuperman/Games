#ifndef  __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define  NAMELONGTH 1024
#define  TELELONGTH     1024
//#define  BOOKSIZE         200
#define  DEFAULTCAY     1

typedef struct PersonInfr//ÿ������Ҫ�洢�����͵绰
{
	char name[NAMELONGTH];
	char tele[TELELONGTH];
}PersonInfr;

typedef struct PhoneBook//һ���绰��������Ҫ200����ϵ��
{
	PersonInfr * Book ;  //test
	unsigned int Size;
	unsigned int Capacity;
}PhoneBook;

typedef void(*fun)(PhoneBook*);


int menu();
void PrintAll(PhoneBook* PhoneBook);
void CleanAll(PhoneBook* PhoneBook);
void InitBook(PhoneBook* PhoneBook);
void AddContact(PhoneBook* PhoneBook);
void FindContact(PhoneBook* PhoneBook);
void SortbyName(PhoneBook* PhoneBook);
void DeletContact(PhoneBook* PhoneBook);
void ChangeContact(PhoneBook* PhoneBook);


#endif