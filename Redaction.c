#include "list.h"
void InsertAfter(Head *MyHead, Node *NewNode, int n)
{
    Node *MyNode=NULL;

    MyNode=MyHead->first;
    if (n!=1)
    {
        while (MyNode->id!=n-1) MyNode=MyNode->next;
    }

    if (MyNode!=NULL)
    {
        if ((MyNode->next==NULL)&&(n!=1))
        {
            MyNode->next=NewNode;
            MyHead->last=NewNode;
        }
        else if (n!=1)
        {
            NewNode->next=MyNode->next;
            MyNode->next=NewNode;
        }
        else if (n==1)
        {
            NewNode->next=MyNode;
            MyHead->first=NewNode;
        }
    }
    else
    {
        NewNode->next=MyNode;
        MyHead->first=NewNode;
    }

    MyHead->cnt++;
    if (n!=1) MyNode->next->id=n;
}

void ChangeAfterInsert(Head *MyHead, int d, int *A)
{
    Node *B;
    int i,m;

    B=FindNodeById(MyHead,d);
    m=B->id; // изменение номеров после вставки
    while (B->next)
    {
        B->next->id=m+1;
        B=B->next;
        m++;
    }

    m=A[MyHead->cnt-1]; // перестановка счетчиков массива goals после вставки элемента списка
    for (i=MyHead->cnt-2; i>d-2; i--) A[i+1]=A[i];
    A[d-1]=m;
}

void DeleteNode(Head *MyHead, int d)
{
    Node *B, *q, *MyNode=NULL;

    B=MyHead->first;
    q=MyHead->last;

    MyNode=FindNodeById(MyHead,d);

    if (MyNode==B)
    {
        MyHead->first=MyNode->next;
        MyNode->next=NULL;
        free(MyNode);
    }
    else
    {
        do
        {
            if(B->next==MyNode)
            {
                if(MyNode==q) MyHead->last=B;
                B->next=MyNode->next;
                MyNode->next=NULL;
                free(MyNode);
                B=NULL;
            }
            else B=B->next;
        }
        while (B!=NULL);
    }
    MyHead->cnt--;
    puts("Element is successfully deleted");
}

void ChangeAfterDelete(Head *MyHead, int d, int *A)
{
    Node *B;
    int i;

    if (d!=MyHead->cnt+1)
    {
        for (i=d-1;i<MyHead->cnt+1;i++) A[i]=A[i+1]; // перестановка счетчика массива goals после удалени€ элемента списка

        B=FindNodeById(MyHead,d+1);
        for (i=d;i<=MyHead->cnt;i++)
        {
            B->id=i;
            B=B->next;
        } // изменение номеров элементов после удалени€
    }
}
int ChangeValue(Node *B, char *s, int n, int k)
{
    char *C=NULL;
    int i,j,z,len,m;

    m=0;
    if ((C=(char*)malloc(30*sizeof(char)))!=NULL)
    {
        while (B->id!=n) B=B->next;

        switch (k)
        {
            case 0:
            {
                strcpy(B->name,s);
            }
                break;
            case 1:
            {
                strcpy(B->surname,s);
            }
                break;
            case 2:
            {
                B->age=atoi(s);
            }
                break;
            case 3:
            {
                B->number=atoi(s);
            }
                break;
            case 4:
            {
                B->salary=atof(s);
            }
                break;
            case 5:
            {
                B->height=atof(s);
            }
                break;
            case 6:
            {
                len=strlen(s);
                for (i=0,m=0;i<len;m++) //заполнение массива goals
                {
                    for (j=0;(s[j+i]!=' ')&&(i+j<len);j++) C[j]=s[j+i];
                    B->goals[m]=atoi(C);
                    for (z=0;z<30;z++) C[z]='\0';
                    i=i+j+1;
                }
            }
                break;
        }
        puts("Ёлемент успешно изменЄн");
        free(C);
    }
    else m=-1;

    return m;
}
