#include <stdio.h>
/*strcat присоединяет строку t в конец строки s*/



void mystrcat(char *s,char *t)
{
    while (*s++)
        ;
    s--;

    while (*s++ = *t++)
        ;
}


int main(void)
{
    char first[10];

    int i;
    for (i=0; i<3;i++ )
        first[i]='a';
    first[i]='\0';

    char second[]= "end";
    printf("f %s s %s\n",first,second);

    mystrcat(first,second);

    printf("f %s \n",first);

    return 0;
}
