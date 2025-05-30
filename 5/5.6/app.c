#include <stdio.h>
#include <ctype.h>
#include <string.h>

void my_reverse(char *);

//считывает строку в s, возвращает ее длину
int my_getline(char *s, int lim)
{
    int c;
    char *zero;

    zero = s;
    while (--lim>0 && (c=getchar()) != EOF && *s != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s - zero;
}

//преобразует строку s в целое число
int my_atoi(char *s)
{
    int sign,n;
   
    while(isspace(*s)) /* пропуск пробелов*/
        s++;
    sign = (*s == '-')? -1 : 1 ;
    if (*s == '-' || *s=='+') /* пропуск знака*/
        s++;
    for ( n = 0; isdigit(*s) ; s++)
        n = 10 * n + (*s - '0');


    return sign * n;
}

// преобразует число в строку символов
void my_itoa(int n, char *s)
{
    int sign;
    char *t;
    t=s;
    if ((sign = n) <0)
        n = -n;
    do{
        *s++ = n % 10 + '0';
    } while ( (n/=10) > 0);
    if(sign < 0)
        *s++= '-';
    *s = '\0';

    my_reverse(t);
}

//обращает порядок элементов в стоке
void my_reverse(char *s)
{
    int c;
    char *p;

    p=s;
    while (*s)
        s++;
    s--;
    while(s > p){
        c = *s;
        *s-- = *p;
        *p++ = c;
    }
}

//возвращает индекс строки t в s, -1 при отсутствии
int my_strindex(char *s, char *t)
{
    char *pt,*ps;
    char *zero_s;
    
    zero_s=s;
    for (;*s;s++){
        for (ps=s,pt=t;*ps==*pt && *pt; pt++,ps++)
            ;
        if (*pt=='\0' && ps !=s)
            return s-zero_s;
    }
    return -1;
}

void my_getop(void)
{}





int main (void)
{

    char arr[10];

    my_itoa(123456789,arr);
    printf("%s\n",arr);
    
   
    
    char *s = "abcdef";
    char *test = "bcd";

    int i = my_strindex(s,test);
    printf("str index at pos %d\n",i);

    return 0;
}
