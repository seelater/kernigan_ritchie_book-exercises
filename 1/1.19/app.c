#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int getline(char line[], int lim);
void reverse(char s[]);

int main(void) {
    char line[MAXLINE];
    int len,c;

    while ((len=getline(line, MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while((c = getchar()) != '\n' && c != EOF ) {
                ++len;
            }
        }
        printf("before = %s\n",line);
        reverse(line);
        printf("after = %s\n",line);
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

void reverse(char s[]) {
    int i;
    int temp;

    i=0;
    while (s[i] != '\0') {
        ++i;
    }
    if (s[--i] == '\n'){
        --i;
    }

    for (int j=0; j < i; ++j,--i) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}


