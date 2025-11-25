#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(void) {
    int c;
    size_t spaces, tabs, nl;

    spaces = tabs = nl = 0;
    while ( (c = getchar()) != EOF ) {
        if (c == ' ') {
           ++spaces;
        }
        if (c == '\t') {
            ++tabs;
        }
        if (c == '\n') {
            ++nl;
        }
    }
    printf("spaces = %zu labs = %zu new lines = %zu\n", spaces, tabs, nl);
    return EXIT_SUCCESS;
}
