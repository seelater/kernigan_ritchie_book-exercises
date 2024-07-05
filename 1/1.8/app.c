#include <stdio.h>

int main()
{
    int c = 0;

    double spaces = 0;
    double tabs = 0;
    double new_lines = 0;

    while ( (c = getchar()) != EOF)
    {
        if ( c == ' ')
        {
           ++spaces;
        }
        if ( c == '\t')
        {
            ++tabs;
        }
        if (c == '\n')
        {
            ++new_lines;
        }
    }

    printf("spaces = %.0f tabs = %.0f new lines = %.0f\n",spaces,tabs,new_lines);
    return 0;
}
