#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define M 124
#define N 5

struct LNode
{
    int id;
    char *name;// имя игрока
    char *surname; // фамилия игрока
    int age; // возраст игрока
    int number; // игровой номер
    float salary; // зарплата (тыс. евро)
    float height; // рост
    int *goals; // количество голов (последние 5 сезонов)
    struct LNode *next;
};

struct LHead
{
    int cnt;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LNode Node;
typedef struct LHead Head;

int menu_main(); // основное меню для работы с программой
int menu_intput(); // меню для выбора между двух чисел
int menu_1(); // меню редактирования
int menu_2(); // меню для поиска элементов
int Read_Field(char *); // считывание признака
void Read_Value(char *); // считывание значения выбранного признака
int scanID(int *); // ввод id элемента пользователем
Head *MakeHead(); // создание головы
Node *MakeNode(); // создание элемента списка
int ReadFile(Head *, Node *, int *, int *); // считывание данных из файла
Node *ReadNode(char *, int *); // считывание элемента списка с клавиатуры
void NodePrint(Node *, int); // вывод элемента списка на экран
void KartPrint(Head *, int *); // вывод картотеки на экран
void InsertAfter(Head *, Node *, int); // вставка элемента
void ChangeAfterInsert(Head *, int, int *); // изменение номеров элементов и счётчиков goals после вставки элемента
void clearNode(Head *, Node *); // отчистка памяти
void DeleteNode(Head *, int); // удаление элемента
void ChangeAfterDelete(Head *, int, int *); // изменение номеров элементов и счётчиков goals после удаления элемента
Node *FindNodeById(Head *, int); // поиск элемента по номеру
int FindNodesByField(Head *, char *(*Fname)(Node *), int, char *, int *); // поиск элементов по значению поля
int ChangeValue(Node *, char *, int, int); // поиск элементов по значению поля
char *name(Node *); // возвращает значение поля name текущего элемента списка
char *surname(Node *); // возвращает значение поля surname текущего элемента списка
char *age(Node *); // возвращает значение поля age текущего элемента списка
char *number(Node *); // возвращает значение поля number текущего элемента списка
char *salary(Node *); // возвращает значение поля salary текущего элемента списка
char *height(Node *); // возвращает значение поля height текущего элемента списка
int Sort1_6(Head *, Node *, char *(*Fname)(Node *), int, int, int *); // сортировка данных
void Sort7(Head *, Node *, int, int *); // сортировка массивов goals
int rewriteFile(FILE *, Head *, int *); // перезапись файла


#endif // LIST_H_INCLUDED
