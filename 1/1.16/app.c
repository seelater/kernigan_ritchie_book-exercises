#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10

int getline(char line[], int lim);
void copy(char to[], char from[]);

int main(void) {
    char line[MAXLINE];
    char longest[MAXLINE];
    int len, maxlen;
    int c;

    maxlen = 0;
    while ((len=getline(line, MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while((c = getchar()) != '\n' && c != EOF ) {
                ++len;
            }
        }
        if (len > maxlen) {
            maxlen = len;
            copy(longest, line);
        }
    }
    if (maxlen > 0) {
        printf("maxlen = %d line = %s",maxlen, longest);
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

void copy(char to[], char from[]) {
    int i;

    i=0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
