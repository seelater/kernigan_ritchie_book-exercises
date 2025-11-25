#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAXSIZE 1000

int main(void) {
    int c;
    size_t index;
    int words[MAXSIZE];

    /*init 0 */
    for (size_t i = 0; i < MAXSIZE; ++i) {
        words[i] = 0;
    }
    
    index = 0;
    while ((c = getchar()) != EOF) {
        if (index >= MAXSIZE) {
            printf("error: too much words");
            break;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            ++index;
        } else {
            ++words[index];
        }
    }

    /*output*/
    for (size_t i = 0; i < MAXSIZE; ++i) {
        for (int j = 0; j < words[i];++j) {
            printf("=");
        }
        if (words[i] == 0) {
            continue;
        }else {
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
