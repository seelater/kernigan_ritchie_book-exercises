#include <stdio.h>

//celsius to fahr
//
int main()
{
    float fahr = 0;
    float celsius = 0;

    int lower = 0;
    int upper = 300;
    int step = 20;
    celsius = lower;

    printf("celsius\tfahr\n");

    while (celsius <= upper)
    {
        fahr = ((9.0 / 5.0)* celsius) + 32;
        printf("%3.0lf %9.1lf\n", celsius, fahr);
        celsius = celsius + step;

    }

    return 0;
}
