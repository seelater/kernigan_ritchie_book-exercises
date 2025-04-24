#include <ctype.h>
#include <stdio.h>
#include "app.h"

/* getint: считывает очередное целое число из входного потока в *pn */

int getint(int *pn)
{

    int c, sign;

    while (isspace(c=getch()) )
        ;
    if (!isdigit(c) &&  c != EOF && c != '+' && c != '-' ){
        ungetch(c); /* не цифра*/
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn= 10 * *pn + ( c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}


int main(void)
{
    int c;
    int x;
    while ((x= getint(&c) )!= EOF){
        if (x == 0)
            break;
        printf("returned %d \n",x);
        printf("*pn  %d\n",c);
    }
    
    return 0;
}


