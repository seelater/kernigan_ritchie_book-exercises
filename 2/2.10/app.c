#include <stdio.h>

int lower(int);

int main (void)
{
    int c=0;
    while((c = getchar())!=EOF )
        {
            printf("%c\n",lower(c));
        }
    return 0;
}

int lower(int c)
{
    return (c>= 'A' && c<='Z') ? c+ 'a'-'A' :  c ;
}
