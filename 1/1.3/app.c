#include <stdio.h>

/*печать таблицы температур для преобразования fahr->celsius 
 * fahr = 0, 20 ... 300; float */


int main()
{
    
    float fahr = 0;
    float celsius = 0;
    int lower = 0;
    int upper = 300;
    int step = 20;
    

    fahr = lower;
    printf("fahr\tcelsius\n");
    while(fahr <= upper)
    {
        celsius = ( 5.0 / 9.0 ) * (fahr - 32);
        printf("%3.lf %6.1lf\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
