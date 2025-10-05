#include <stdio.h>
#include <stdlib.h> /*atoi*/
#include <string.h> /*strcpy getline */

#define TAILSIZE 10
#define MAXLINES 5000 /*максимальное количество строк*/
#define MAXLEN 1000 /*максимальная длина строки*/
#define ALLOCMEM MAXLINES * MAXLEN /*память под хранение строк*/

/*tail: вывод последних n строк из входного потока */

int readlines(char *lineptr[], char *buf, int nlines);
void writelines(char *lineprt[], int nlines, int tailsize);
int my_getline(char *, int);

int main(int argc, char *argv[])
{
    int c = 0;
    int tailsize = 0; /*количество строк начиная с конца для вывода*/
    int user_tailsize = 0; /*bool*/
    char *lineptr[MAXLINES];
    char buf[ALLOCMEM]; /*массив для хранения строк*/
    int nlines = 0; /* кол-во введенных строк*/

    printf("argc %i\n",argc);

    while (--argc > 0 && **++argv == '-') {
        while ((c = *++argv[0])>0)
            switch (c) {
                case 'n':
                    user_tailsize = 1;
                    break;
                default:
                    printf("tail: illegal option %c\n",c);
                    argc = 0;
                    break;
            }
    }
    tailsize = (user_tailsize > 0) ? atoi(*argv) : TAILSIZE;
    printf("after while %i\n",argc);

    if (argc!=1 )
        printf("Usage; tail -n lines\n");
    else if ((nlines = readlines(lineptr,buf,MAXLINES)) >= 0 ) {
        writelines(lineptr,nlines,tailsize);
    } else 
        puts("empty input");
    
    return 0;
}

int readlines(char *lineptr[], char *mem_size, int maxlines)
{
    int len,nlines;
    char line[MAXLEN];
    char *p,*p_end;

    p = mem_size;
    p_end = mem_size+ALLOCMEM;
    nlines = 0;
    len = 0;

    while ((len = my_getline(line,MAXLEN)) > 0) 
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

void writelines(char *lineprt[],int nlines, int tailsize)
{
    if (tailsize >= nlines)
        tailsize = nlines;
    for (; tailsize>0;--tailsize)
        printf("%s\n",lineprt[nlines-tailsize]);
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
