#include <ctype.h>
#include <stdio.h>
#include "app.h"

/* getfloat: считывает очередное число из входного потока в *pn */

int getfloat(double *pn)
{

    int c, sign;
    int solo_sign;
    double frac_part;

    while (isspace(c=getch()) )
        ;
    if (!isdigit(c) &&  c != EOF && c != '+' && c != '-' && c !='.'){
        ungetch(c); /* не цифра*/
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        solo_sign = c;
        c = getch();
        if ( !isdigit(c)){
            if (c != EOF)
                ungetch(c);
            //*pn=0;
            ungetch(solo_sign);
            //return getch();
            return 0;
        }

    }

    //целая часть
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn= 10.0 * *pn + ( c - '0');
    //дробная часть
    if (c == '.')
        c = getch();
    for (frac_part=1.0;isdigit(c);c=getch()){
        *pn = 10* *pn + (c - '0');
        frac_part *=10;
    }

    *pn *= sign/frac_part;
    if (c != EOF)
        ungetch(c);

    return c;
}


int main(void)
{
    double c;
    int x;
    while ((x= getfloat(&c) )!= EOF){
        if (x == 0 )
             break;
             
        printf("returned %d \n",x);
        printf("*pn  %f\n",c);
        }
    
    return 0;
}


