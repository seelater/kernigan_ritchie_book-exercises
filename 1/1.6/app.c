#include <stdio.h>

int main()
{
    int c;
    while ( (c=getchar()) !=EOF ) 
    {
        printf("%i\n",getchar() != EOF );
    }

    return 0;
}
