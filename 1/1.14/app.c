#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ENG_SIZE 26
#define NUM_SIZE 10

int main()
{
    int c;
    int symbols[ENG_SIZE];
    int numbers[NUM_SIZE]; 

    /*init 0*/
    for (size_t i = 0; i < ENG_SIZE; ++i) {
        symbols[i] = 0;
    }
    for (size_t i = 0; i < NUM_SIZE; ++i) {
        numbers[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c >='a' && c <='z') {
            ++symbols[c - 'a'];
        }else if (c >= '0' && c <= '9') {   
            ++numbers[c - '0'];
        }
    }
    /*output*/
    for (int i = 0; i < ENG_SIZE; i++) {
        printf("%c ", i + 'a');
        for (int j = 1; j <= symbols[i]; j++) {
            printf("=");
        }
        printf("\n");
    }

    puts("-----------------");
    for ( int i = 0; i<NUM_SIZE; i++) {
        printf("%i ",i);
        for (int j = 1; j <= numbers[i]; j++) {
            printf("=");
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
