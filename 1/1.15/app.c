#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/*convert_fahr_to_cels */
double convert_to_celsius(double);

int main(void) {
    double fahr;
    
    fahr = LOWER;
    while (fahr <= UPPER) {
        printf("fahr= %5.0f celsius= %5.1f\n", fahr, convert_to_celsius(fahr));
        fahr = fahr + STEP;
    }
    return EXIT_SUCCESS;
}

double convert_to_celsius(double fahr) {
    double celsius;

    celsius = (5.0 / 9.0) * (fahr - 32);
    return celsius;
}

