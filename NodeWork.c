#include "list.h"

Head *MakeHead()
{
    Head *A=NULL;

    if ((A=(Head*)malloc(sizeof(Head)))!=NULL)
    {
        A->cnt=0;
        A->first=NULL;
        A->last=NULL;
    }

    return A;
}

Node *MakeNode()
{
    Node *B=NULL;

    if ((B=(Node*)malloc(sizeof(Node)))!=NULL)
    {
        if ((B->name=(char*)malloc(M*sizeof(char)))!=NULL)
        {
            if ((B->surname=(char*)malloc(M*sizeof(char)))!=NULL)
            {
                if ((B->goals=(int*)malloc(N*sizeof(int)))!=NULL)
                {
                    B->id=1;
                    B->next=NULL;
                }
                else
                {
                    free(B);
                    free(B->name);
                    free(B->surname);
                    B=NULL;
                }
            }
            else
            {
                free(B);
                free(B->name);
                B=NULL;
            }
        }
        else
        {
            free(B);
            B=NULL;
        }
    }

    return B;
}
void NodePrint(Node *B, int a)
{
    int i;
    printf("| %2d | %9s     |%9s   |%5d |%6d  | %6.2f  |%5.2f  |", B->id, B->name, B->surname, B->age, B->number, B->salary, B->height);
    for (i=0;i<a;i++) printf(" %3d ",B->goals[i]);
    printf("|");
}
void KartPrint(Head *MyHead, int *A)
{
    Node *B=NULL;
    int i;

    B=MyHead->first;
    if (B!=NULL)
    {
        printf("\n| %2s |%8s       |%10s  |%6s|%6s|%5s |%5s| %16s        |\n","¹"," name "," surname "," age "," number "," salary "," height "," goals ");
        printf("+-----+--------------+------------+------+--------+---------+--------+-------------------------+\n");
        for (i=0;i<MyHead->cnt;i++)
        {
            NodePrint(B,A[i]);
            printf("\n");
            B=B->next;
        }
        puts("");
    }
    else puts("     | FILE IS EMPTY |\n");
}

void clearNode(Head *MyHead, Node *B)
{
    B=MyHead->first;
    while (B!=NULL)
    {
        free(B->name);
        free(B->surname);
        free(B->goals);
        free(B);
        B=B->next;
    }
    free(MyHead);
}

int rewriteFile(FILE *DF, Head *MyHead, int *A)
{
    Node *B=NULL;
    int i,j,key;

    key=1;
    if ((DF=fopen("ManU.csv","w"))!=NULL)
    {
        B=MyHead->first;
        i=0;
        while (B)
        {
            fprintf(DF,"%s;",B->name);
            fprintf(DF,"%s;",B->surname);
            fprintf(DF,"%d;",B->age);
            fprintf(DF,"%d;",B->number);
            fprintf(DF,"%.2f;",B->salary);
            fprintf(DF,"%.2f;",B->height);
            if (A[i]!=1)
            {
                for (j=0;j<A[i]-1;j++) fprintf(DF,"%d;",B->goals[j]);
                fprintf(DF,"%d\n",B->goals[A[i]-1]);
            }
            else fprintf(DF,"%d\n",B->goals[0]);
            i++;
            B=B->next;
        }
        if (fclose(DF)==EOF)
        {
            perror("Closing File is failed");
            key=0;
        }
    }
    else
    {
        perror("Opening File is failed");
        key=0;
    }

    return key;
}
