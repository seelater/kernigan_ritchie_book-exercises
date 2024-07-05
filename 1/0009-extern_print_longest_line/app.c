#include<stdio.h>

#define MAXLINE 1000

int max = 0;
char line[MAXLINE] = {0}
char longest[MAXLINE] = {0}


int getline(void);
void copy(void);


int main()
{
    int len = 0;
    extern int max;
    extern char longest[];

    while ( (len = getline()) > 0)
    {
        if (len > max) 
        {
            max = len;
            copy();
        }
    }
    if (max > 0)
    {
        printf("%s", longest)
    }

    return 0;
}


/* getline: specialized version */
int getline(void)
{
    int c = 0; 
    extern char line[];
    for (int i = 0; (i < MAXLINE - 1) && (c=getchar()) != EOF && (c != '\n'); ++i)
    {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}
/* copy: specialized version */
void copy(void)
{
    extern char line[], longest[];
    int i = 0;
    while ((longest[i] = line[i]) != '\0')
    ++i;
}


