#include <stdio.h>

int main()
{
    int c = 0;
    while ( (c = getchar()) != EOF)
    {
        if ( c == ' ' || c == '\n' || c == '\t' )
        {
            printf("\n");
        }else
        {
            printf("=");
        }
    }

    return 0;
}
