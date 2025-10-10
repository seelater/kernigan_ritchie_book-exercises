#include <stdio.h>
#include "app.h"
#include <string.h>

#define MAXSIZE 1000
#define MAXLINES 5000
#define ALLOCMEM MAXLINES * MAXSIZE

int readlines(char *lineptr[], char *mem, int maxlines)
{
    int len,nlines;
    char line[MAXSIZE];
    char *p,*p_end;

    p = mem;
    p_end = mem + ALLOCMEM;
    nlines = 0;
    len = 0;

    while ((len = my_getline(line,MAXSIZE)) > 0)
        if ( nlines >= maxlines || p+len > p_end)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
            p += len;
        }

    return nlines;
}

void writelines(char *lineptr[],int nlines,int reverse)
{
    int i;
    if (reverse == 0)
        for (i = 0; i < nlines ; ++i)
            printf("%s\n",lineptr[i]);
    else 
        for(i = nlines-1; i >= 0; --i)
            printf("%s\n", lineptr[i]);
}

int my_getline(char *s, int lim)
{
    int c = 0;
    char *tmp = s;

    while (--lim>0 && (c = getchar())!= EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s-tmp;
}

