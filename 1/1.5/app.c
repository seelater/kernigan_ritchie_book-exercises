#include <stdio.h>

int main()
{
    int end = 0;
    for (int fahr = 300; fahr >= end; fahr = fahr - 20 )
    {
        printf("%3i %6.1lf\n",fahr, (5.0/9.0)*(fahr-32));
    }
    return 0;
}
