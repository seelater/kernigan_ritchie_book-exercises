#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

double convert_to_celsius(double);
void print_temp(double,double);

int main()
{
    double fahr = LOWER;
    while (fahr <= UPPER)
    {
        print_temp(fahr,convert_to_celsius(fahr));
        fahr = fahr + STEP;
    }
    return 0;
}

double convert_to_celsius(double fahr)
{
    double celsius=0;
    celsius = (5.0 / 9.0) * (fahr - 32);
    return celsius;
}

void print_temp(double temp1, double temp2)
{
    printf("%.1lf  %.1lf\n",temp1,temp2);
}
