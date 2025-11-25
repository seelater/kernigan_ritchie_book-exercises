#include <stdio.h> 
#include <stdlib.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            putchar('\n');
        }else {
            putchar(c);
        }
    }
    return EXIT_SUCCESS;
}
