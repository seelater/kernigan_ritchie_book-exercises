#include<stdio.h>

#define N 4

// x* tab = x * n 


int main()
{
    int c = 0;
    int counter = 0;
    while ( (c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            ++counter;
            for ( int i = 0; i < N; ++i){
                putchar(' ');
            }
        }
        if ( c == '\n')
        {
            printf("there is %i, spaces \n",N*counter);
            counter = 0;
        }
    }
    return 0;
}

