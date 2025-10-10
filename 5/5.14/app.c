#include <stdio.h>
#include <string.h>
#include "app.h"

#define MAXLINES 5000 /*макс колво строк*/
#define MAXSIZE 1000 /*макс длинна строки*/
#define MEM MAXLINES * MAXSIZE

char *lineptr[MAXLINES]; /*указатели на строки*/
char buf[MEM]; /*резерв памяти под строки*/


int numcmp(const char *,const char *);

int main(int argc, char *argv[])
{
    int nlines = 0; /*кол-во считанных строк*/
    int numeric = 0; /* 1 если числовая ( по количеству символов) сортировка*/
    int c =0;
    int reverse = 0;

    while(--argc > 0 && **++argv == '-')
        while ( c = *++argv[0])
        switch (c) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            default :
                printf("sort: illegal option %c\n",c);
                argc = 0;
                break;
        }
    if (argc > 0)
        printf("Usage: ./app -n -r lines\n");
    else if ( (nlines = readlines(lineptr,buf,MAXLINES)) >= 0){
        my_qsort((void**) lineptr,0,nlines-1,
                (int (*)(void *,void *))(numeric ? numcmp : strcmp));
        writelines(lineptr,nlines,reverse);
        return 0;
    } else {
        printf("input too big to sort \n");
        return 1;
    }

    return 0;
}


#include <stdlib.h>

int numcmp(const char *s1, const char *s2)
{
    double v1,v2;
    
    v1 = atof(s1);
    v2 = atof(s2);

    if (v1<v2)
        return -1;
    else if(v1>v2)
        return 1;
    else 
        return 0;
}
