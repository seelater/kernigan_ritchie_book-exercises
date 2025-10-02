#include <stdio.h>
#include <stdlib.h>

/*default tabstep*/
#define TABINC 4
#define TABSIZE 4

#define MAXSIZE 12

/* detab: замена символов табуляции пробелами */
int main(int argc, char* argv[])
{
    int tab_stop[MAXSIZE]={0};
    int tab_stop_count = 0;

    while (--argc > 0)
        tab_stop[tab_stop_count++] = atoi(*++argv);

    /*default tabstop size*/
    if (tab_stop_count == 0)
        while (tab_stop_count < MAXSIZE) {
            tab_stop[tab_stop_count] = TABSIZE + (TABINC * tab_stop_count);
            tab_stop_count++;
        }

    /*debug */
    for (int i = 0; i<MAXSIZE;++i)
        printf("%i\t",tab_stop[i]);
    printf("\n tab_stop_count = %i\n",tab_stop_count);

    /*detab part*/
    int c = 0;
    int counter = 0;
    int p=0;

    while ((c = getchar()) != EOF) {
        counter++;
        if (c == '\t') {
            for (p = tab_stop_count-1; counter < tab_stop[p]; --p)
                if (p<0)
                    break;
                
                
            p++; 
            for (int i = counter; i <= tab_stop[p] ; ++i){
                putchar(' ');
                if (i>100)
                    break;
            }
        } else
            putchar(c);
        

        if (c == '\n')
            counter = 0;
    }

    return 0;
}
