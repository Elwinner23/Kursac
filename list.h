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
    char *name;// ��� ������
    char *surname; // ������� ������
    int age; // ������� ������
    int number; // ������� �����
    float salary; // �������� (���. ����)
    float height; // ����
    int *goals; // ���������� ����� (��������� 5 �������)
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

int menu_main(); // �������� ���� ��� ������ � ����������
int menu_intput(); // ���� ��� ������ ����� ���� �����
int menu_1(); // ���� ��������������
int menu_2(); // ���� ��� ������ ���������
int Read_Field(char *); // ���������� ��������
void Read_Value(char *); // ���������� �������� ���������� ��������
int scanID(int *); // ���� id �������� �������������
Head *MakeHead(); // �������� ������
Node *MakeNode(); // �������� �������� ������
int ReadFile(Head *, Node *, int *, int *); // ���������� ������ �� �����
Node *ReadNode(char *, int *); // ���������� �������� ������ � ����������
void NodePrint(Node *, int); // ����� �������� ������ �� �����
void KartPrint(Head *, int *); // ����� ��������� �� �����
void InsertAfter(Head *, Node *, int); // ������� ��������
void ChangeAfterInsert(Head *, int, int *); // ��������� ������� ��������� � ��������� goals ����� ������� ��������
void clearNode(Head *, Node *); // �������� ������
void DeleteNode(Head *, int); // �������� ��������
void ChangeAfterDelete(Head *, int, int *); // ��������� ������� ��������� � ��������� goals ����� �������� ��������
Node *FindNodeById(Head *, int); // ����� �������� �� ������
int FindNodesByField(Head *, char *(*Fname)(Node *), int, char *, int *); // ����� ��������� �� �������� ����
int ChangeValue(Node *, char *, int, int); // ����� ��������� �� �������� ����
char *name(Node *); // ���������� �������� ���� name �������� �������� ������
char *surname(Node *); // ���������� �������� ���� surname �������� �������� ������
char *age(Node *); // ���������� �������� ���� age �������� �������� ������
char *number(Node *); // ���������� �������� ���� number �������� �������� ������
char *salary(Node *); // ���������� �������� ���� salary �������� �������� ������
char *height(Node *); // ���������� �������� ���� height �������� �������� ������
int Sort1_6(Head *, Node *, char *(*Fname)(Node *), int, int, int *); // ���������� ������
void Sort7(Head *, Node *, int, int *); // ���������� �������� goals
int rewriteFile(FILE *, Head *, int *); // ���������� �����


#endif // LIST_H_INCLUDED
