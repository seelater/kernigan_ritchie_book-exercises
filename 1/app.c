#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TARGETLEN 80

int getline(char line[], int lim);

int main(void) {
    char line[MAXLINE];
    int len;
    int c;

    while ((len=getline(line, MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while((c = getchar()) != '\n' && c != EOF ) {
                ++len;
            }
        }
        if (len >= TARGETLEN) {
            printf("len = %d line = %s",len, line);
        }
    }
    return EXIT_SUCCESS;
}

int getline(char s[], int lim) {
    int i,c;
    
    for (i = 0; i < lim-1 && (c=getchar())!= EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i]='\n';
        ++i;
    }
    s[i]= '\0';
    return i;
}

