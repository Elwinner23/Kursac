#include"list.h"

int menu_main()
{
    int c,len,key;
    char *s=NULL;

    puts("\n   Menu: 1) Redaction; 2) Search 3) Sorting 4) Print on screen;");

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose option - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"1")==0) c=1;
            else if (strcmp(s,"2")==0) c=2;
            else if (strcmp(s,"3")==0) c=3;
            else if (strcmp(s,"4")==0) c=4;
            else c=0;
            if ((c!=1)&&(c!=2)&&(c!=3)&&(c!=4))
            {
                puts("Unacceptable option, try again");
                printf("Choose option - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error at memory allocation");
        c=-1;
    }

    return c;
}

int menu_intput()
{
    int v,len,key;
    char *s=NULL;

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose option - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"0")==0) v=0;
            else if (strcmp(s,"1")==0) v=1;
            else v=3;
            if ((v!=0)&&(v!=1))
            {
                puts("Unacceptable option, try again");
                printf("Choose option - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error at memory allocation");
        v=-1;
    }

    return v;
}

int menu_1()
{
    int v,len,key;
    char *s=NULL;

    printf("  Redaction: 1) Add element 2) Delete element 3) Change element\n");

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose option - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"1")==0) v=1;
            else if (strcmp(s,"2")==0) v=2;
            else if (strcmp(s,"3")==0) v=3;
            else v=0;
            if ((v!=1)&&(v!=2)&&(v!=3))
            {
                puts("Unacceptable option, try again");
                printf("Choose option - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error at memory allocation");
        v=-1;
    }

    return v;
}

int menu_2()
{
    int v,len,key;
    char *s=NULL;

    printf("  Search: 1) By number of element 2) By value of the field\n");

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose option - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"1")==0) v=1;
            else if (strcmp(s,"2")==0) v=2;
            else v=0;
            if ((v!=1)&&(v!=2))
            {
                puts("Unacceptable option, try again");
                printf("Choose option - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error at memory allocation");
        v=-1;
    }

    return v;
}
