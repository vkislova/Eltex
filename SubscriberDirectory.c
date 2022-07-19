// Абонентский справочник (имя, фамилия, номер телефона) для хранения информации о 10 абонентах
// с возможностью добавления новой записи, удаления записи, поиска по фамилии, просмотра всех записей
//19.07.2022

#include <stdio.h>
#include <string.h>

#define MAXNAMEL 20 //максимальная длина имени -1
#define MAXSURNAML 24 //максимальная длина фамилии -1
#define SIZE 10 //размер абонентского справочника

struct subscrDirectory {
char name[MAXNAMEL];
char surname[MAXSURNAML];
long int number;
};

struct subscrDirectory directory[SIZE] = {{"Иван","Грозный",79134567845},{"Питер","Паркер",12126789006}};
int number = 2; //количество ненулевых записей в справочнике
void add(void);
void delete(int);
int search(void);
void showAll(void);


int main(void)
{	
	int menuItem;
	int contin = 1; //переменная для бесконечного цикла
	int index;
	enum menu {ADD = 1, DELETE, SEARCH, SHOW, EXIT}; //перечисление с пунктами меню
	printf("\tМеню\n1.Добавить новую запись\n2.Удалить запись\n3.Найти по фамилии\n4.Показать список всех абонентов\n5.Выйти\nВведите номер пункта меню\n");
	while(contin)
	{
		scanf("%d",&menuItem);
		switch(menuItem)
		{
			case 1:
			{
			 if(number < SIZE)
			 {
			 	add();
				printf("\nГотово!\nВведите номер пункта меню\n");
			 }
			 else printf("\nСправочник переполнен! Сначала удалите абонента!\nВведите номер пункта меню\n");
			 break;
			}
			case 2:
			{
			if(number > 0)
			 {
				 index = search(); 
				 if(index == number)
					printf ("Абонент не найден\n");
				 else delete(index);
			 }
			 else printf("Справочник пустой! Сначала добавьте абонента!");
			 printf("\nВведите номер пункта меню\n");
			 break;
			}
			case 3:
			{
			 index = search();
			 if(index == number)
				printf ("Абонент не найден\n");
			 else printf("%s\t%s\t\t%ld\n",directory[index].name, directory[index].surname, directory[index].number);
			 printf("\nВведите номер пункта меню\n");
			 break;
			}
			case 4:
			{
			 showAll();
			 printf("\nВведите номер пункта меню\n");
			 break;
			}
			case 5:
			{
			 contin = 0;
			 break;
			}
		}
	
	}
	return 0;
}

void add(void)
{
	printf("Введите имя абонента, фамилию и номер телефона\n");
	scanf("%s %s %ld",&directory[number].name[0], &directory[number].surname[0], &directory[number].number);
	number++;
}

void delete(int i)
{
	int j = i;
	for(j; j < number; j++)
	{
		strcpy(directory[j].name,directory[j+1].name);
		strcpy(directory[j].surname,directory[j+1].surname);
		directory[j].number = directory[j+1].number;
	}
	strcpy(directory[j].name,"");
	strcpy(directory[j].surname,"");
	directory[j].number = 0;
	number--;
	printf("Готово!\n");
}

int search(void)
{
	int i = 0;
	printf("Введите фамилию абонента\n");
	char newSurname[MAXSURNAML];
	scanf("%s", &newSurname[0]);
	while (strcmp(newSurname, directory[i].surname) != 0 && i<number)
		i++;
	return i;
}

void showAll(void)
{
	if(number != 0)
	{
		printf("Абонентский справочник содержит %d записей\nИмя\tФамилия\t\tНомер телефона\n",number);
		for(int i=0; i<number; i++)
		{
			printf("%s\t%s\t\t%ld\n",directory[i].name, directory[i].surname, directory[i].number);
		}
	}
	else printf("Справочник пустой!");
}



