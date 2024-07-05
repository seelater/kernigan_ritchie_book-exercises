#include <stdio.h>

#define IN 1 //внутри слова
#define OUT 0 // снаружи слова

/*подсчет строк сслов имволов */

int main()
{
    int c, nc, nl, nw, state;
    state = OUT;
    nc = nl = nw = 0;

    while ( (c = getchar() ) != EOF)
    {
        ++nc;
        if ( c == '\n' )
        {
            ++nl;
        }
        if ( c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;   
        }else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("lines = %d words = %d characters = %d\n", nl, nw, nc);

    return 0;
}


