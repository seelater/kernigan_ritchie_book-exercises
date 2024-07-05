#include <stdio.h>

int main()
{
    int c = 0;
    int nwhite = 0;
    int nother = 0;
    
    int ndigit[10] = {0};

    while ( (c = getchar()) !=EOF )
    {
        if ( c >= '0' && c <= '9')
        {
            ++ndigit[c - '0'];
        }else if ( c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        }else
        {
            ++nother;
        }
    }

    printf("цифры = ");
    for ( int i = 0; i<10; i++)
    {
        printf(" %d",ndigit[i]);
    }
    printf(" символы разделители = %d прочие символы = %d\n", nwhite, nother);

    return 0;
}

