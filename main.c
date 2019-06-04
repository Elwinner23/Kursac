#include "list.h"
int main()
{
    Head *p0=NULL;
    Node *p=NULL;
    char *(*kindF[6])(Node *);
    char s[M];
    int A[100];
    int key1,key2;
    int n,m,c,v,d,k;
    FILE *df=NULL;

    kindF[0]=name;
    kindF[1]=surname;
    kindF[2]=age;
    kindF[3]=number;
    kindF[4]=salary;
    kindF[5]=height;

    p0=MakeHead();
    if (p0)
    {
        key1=0;
        key1=ReadFile(p0,p,A,&n);
        if (key1==1)
        {
            puts("\t Working with electronic table");
            do
            {
                c=menu_main(); // основное меню
                if (c!=-1)
                {
                    key2=1;
                    switch (c)
                    {
                        case 1:
                        {
                            do
                            {
                                v=menu_1(); // редактирование
                                if (v!=-1)
                                {
                                    switch (v)
                                    {
                                        case 1: // добавление
                                        {
                                            printf("Specify the number of the addition line - ");
                                            n++;
                                            d=scanID(&n);
                                            n--;
                                            if (d!=-1)
                                            {
                                                puts("Enter an item");
                                                p=ReadNode(s,&(A[n]));
                                                if (p!=NULL)
                                                {
                                                    InsertAfter(p0,p,d);
                                                    puts("Item successfully added");
                                                    ChangeAfterInsert(p0,d,A);
                                                    n++;
                                                }
                                                else
                                                {
                                                    key2=0;
                                                    key1=0;
                                                    free(p);
                                                    clearNode(p0,p);
                                                }
                                            }
                                            else
                                            {
                                                key2=0;
                                                key1=0;
                                                clearNode(p0,p);
                                            }
                                        }
                                            break;
                                        case 2: // удаление
                                        {
                                            if (n==0) puts("Delete is unavailable, few number of elements");
                                            else
                                            {
                                                printf(" Choose id of element, which should be deleted - ");
                                                d=scanID(&n);
                                                if (d!=-1)
                                                {
                                                    DeleteNode(p0,d);
                                                    n--;
                                                    ChangeAfterDelete(p0,d,A);
                                                }
                                            }
                                        }
                                            break;
                                        case 3: // изменение
                                        {
                                            if (n==0) puts("Change is unavailable, few number of elements");
                                            else
                                            {
                                                printf(" Choose id of element, which should be changed - ");
                                                d=scanID(&n);
                                                if (d!=-1)
                                                {
                                                    k=Read_Field(s);
                                                    printf("Input new value: ");
                                                    Read_Value(s);
                                                    p=p0->first;
                                                    m=ChangeValue(p,s,d,k);
                                                    if (m!=-1)
                                                    {
                                                        if (k==6) A[d-1]=m;
                                                    }
                                                    else
                                                    {
                                                        key2=0;
                                                        key1=0;
                                                        clearNode(p0,p);
                                                    }
                                                }
                                                else
                                                {
                                                    key2=0;
                                                    key1=0;
                                                    clearNode(p0,p);
                                                }
                                            }
                                        }
                                            break;

                                        default:
                                            break;
                                    }

                                    if (key2==1)
                                    {
                                        printf("\n Stay at redaction? 1-Yes , 0-No\n");
                                        key2=menu_intput();
                                        if (key2==-1)
                                        {
                                            key2=0;
                                            key1=0;
                                            clearNode(p0,p);
                                        }
                                        else
                                        {
                                            puts("");
                                        }; // завершение или продолжение работы в разделе
                                    }
                                    else
                                    {
                                        key2=0;
                                        key1=0;
                                        clearNode(p0,p);
                                    }
                                }
                                else
                                {
                                    key2=0;
                                    key1=0;
                                    clearNode(p0,p);
                                }
                            }
                            while (key2==1);
                        }
                            break;
                        case 2: // поиск
                        {
                            if (n!=0)
                            {
                                v=menu_2();
                                if (v!=-1)
                                {
                                    switch (v)
                                    {
                                        case 1:
                                        {
                                            printf(" Specify the number of the item you want to display - ");
                                            d=scanID(&n);
                                            if (d!=-1)
                                            {
                                                p=FindNodeById(p0,d);
                                                NodePrint(p,A[d-1]);
                                                printf(" |\n\n");
                                            }
                                            else
                                            {
                                                key1=0;
                                                clearNode(p0,p);
                                            }
                                        }
                                            break;
                                        case 2:
                                        {
                                            d=Read_Field(s);
                                            printf("Enter the value of the field: ");
                                            Read_Value(s);
                                            m=FindNodesByField(p0,kindF[d],d,s,A);
                                            if (m==0) puts("No items found\n");
                                            else if (m!=-1) printf("Found %d items\n\n",m);
                                            else
                                            {
                                                puts("Error at memory allocation");
                                                key1=0;
                                                clearNode(p0,p);
                                            }
                                        }
                                            break;
                                    }
                                }
                                else
                                {
                                    key1=0;
                                    clearNode(p0,p);
                                }
                            }
                            else puts("Search is impossible, the file is empty\n");
                        }
                            break;
                        case 3:
                        {
                            if (n==0) puts("Sorting is impossible, the elements are not available\n");
                            else
                            {
                                printf("Sort: 0) in ascending order; 1) descending\n");
                                v=menu_intput();
                                if (v!=-1)
                                {
                                    d=Read_Field(s);
                                    if (d!=6)
                                    {
                                        key1=Sort1_6(p0,p,kindF[d],d,v,A);
                                        if (key1==0) clearNode(p0,p);
                                    }
                                    else
                                    {
                                        Sort7(p0,p,v,A);
                                    }
                                }
                                else
                                {
                                    key1=0;
                                    clearNode(p0,p);
                                }
                            }
                        }
                            break;
                        case 4:
                        {
                            KartPrint(p0,A);
                        }
                            break;

                        default:
                            break;
                    }
                    if (key1==1)
                    {
                        printf("Would you like to continue working with the program? 1-Yes , 0-No\n");
                        key1=menu_intput();
                        if (key1==0)
                        {
                            key1=rewriteFile(df,p0,A);
                            if (key1==0) clearNode(p0,p);
                            else key1=0;
                        }
                        else if (key1==-1)
                        {
                            key1=0;
                            clearNode(p0,p);
                        }
                    }
                    else
                    {
                        key1=0;
                        clearNode(p0,p);
                    }
                }
                else
                {
                    key1=0;
                    clearNode(p0,p);
                }
            }
            while (key1==1);

        }
        else {}; // в функции выводятся сообщения об ошибках
    }
    else puts("Error at memory allocation");


    return 0;
}



