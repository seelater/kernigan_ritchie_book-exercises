#include <stdio.h>

#define ENG_SIZE 26
#define NUM_SIZE 10

int main()
{
    int c = 0;
    int symbols[ENG_SIZE] = {0};
    int numbers[NUM_SIZE] = {0}; 
    while ( (c = getchar())!=EOF)
    {
        if (c >='a'&& c <='z')
        {
            ++symbols[c - 'a'];
        }else if ( c >= '0' && c <= '9')
        {   
            ++numbers[c - '0'];
        }
    }
    for (int i = 0; i<ENG_SIZE; i++)
    {
        printf("%2i ",i);
        for (int j = 1; j <= symbols[i]; j++)
        {
            printf("=");
        }
        printf("\n");
    }
    puts("-----------------");
    for ( int i = 0; i<NUM_SIZE; i++)
    {
        printf("%2i ",i);
        for (int j = 1; j <= numbers[i]; j++)
        {
            printf("=");
        }
        printf("\n");
    }

    return 0;
}
