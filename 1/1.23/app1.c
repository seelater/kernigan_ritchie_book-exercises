#include <stdio.h>


int main()
{
    int c =0;
    while ((c = getchar() ) != EOF )
    {
        if (c == '*')
            puts("star");
        else
        putchar(c);
    }


    return 0;
}
