#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 5

int getline(char line[], int lim);
void remove_end_spaces(char s[]);

int main(void) {
    char line[MAXLINE];
    int len,c;

    while ((len=getline(line, MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while((c = getchar()) != '\n' && c != EOF ) {
                ++len;
            }
        }
        printf("before = %s||\n",line);
        remove_end_spaces(line);
        printf("after = %s||\n",line);
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

void remove_end_spaces(char s[]) {
    int i,len;

    i=len=0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;
    len=i;

    while (s[i]==' ' || s[i]== '\t') {
        --i;
    }
    if (len == '\n') {
        s[i]='\n';
    }
    s[++i]='\0';
}


