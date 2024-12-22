#include <stdio.h>

/*печать таблицы температур для преобразования fahr->celsius 
 * fahr = 0, 20 ... 300; float */


int main()
{
    
    float fahr, celsius;
    float lower, upper,step;

    lower = 0;   /*lower limit of temp */
    upper = 300; // upper limit 
    step = 20;   //step size
    

    fahr = lower;
    printf("fahr\tcelsius\n");
    while(fahr <= upper)
    {
        celsius = ( 5.0 / 9.0 ) * (fahr - 32);
        printf("%3.lf %10.1lf\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
