#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c = 0;
    int state = OUT;

    while ((c = getchar()) != EOF)
    {
        if ( c != ' ' && c != '\n' && c != '\t' && c !=',' && c !='.' && c != ';' )
        {
            state = IN;
            putchar('=');
        }else if (state == IN)
        {
            state = OUT;
            putchar('\n');
        }
    }
    return 0;
}
