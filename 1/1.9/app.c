#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;
    size_t is_space;

    is_space = 0;

    while((c=getchar()) != EOF) {
        if (c == ' ' && is_space == 0) {
            putchar(c);
            is_space = 1;
        } 
        if (c != ' '){
            putchar(c);
            is_space = 0;
        }
   }
   return EXIT_SUCCESS;
}
