#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAXSIZE 1000

int main(void) {
    int c, max_height;
    size_t index;
    int words[MAXSIZE];

    /*init 0 */
    for (size_t i = 0; i < MAXSIZE; ++i) {
        words[i] = 0;
    }
    
    index = 0;
    max_height = 0;
    while ((c = getchar()) != EOF) {
        if (index >= MAXSIZE) {
            printf("error: too much words");
            break;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            ++index;
        } else {
            ++words[index];
            if (words[index] > max_height) {
                max_height=words[index];
            }
        }
    }

    /*output*/

    while (max_height) {
        for (size_t i = 0; i < MAXSIZE; ++i) { 
            if (words[i] == 0) {
                continue;
            }else if (max_height - words[i] <= 0) {
                printf("# ");
            }else {
                printf("  ");
            }
        }
        --max_height;
        printf("\n");
    }

    return EXIT_SUCCESS;
}
