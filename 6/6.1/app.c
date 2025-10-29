
#include <stdio.h>
#include <ctype.h>
/*getword: считывает очередное слово или символ из потока ввода 
 * и возвращает первый символ. EOF или сам символ если он не алфавитный*/

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word; 
    int in = 1;
    int out = 0;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    /*comment check*/

    if (!isalpha(c) && c != '#' ) {
        *w = '\0';
        return c;
    }
    for (;--lim>0;w++)
        if (!isalnum(*w = getch()) && *w != '_' && *w != ' ' ){
            ungetch(*w);
            break;
        }
    *w ='\0';

    return word[0];
}
