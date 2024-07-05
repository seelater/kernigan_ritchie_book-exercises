#include<stdio.h>

#define SPACES_IN_TAB 4


int main()
{

    int c =0;
    int spaces_count = 0;
    while ( (c = getchar()) !=EOF )
    {
        if (c == ' ')
        {
            spaces_count++;
            if (spaces_count == SPACES_IN_TAB)
            {
                putchar('\t');
                spaces_count = 0;
            }

        }else if ( c != ' ' && spaces_count != 0 ) 
        {
            for (int i = 0; i < spaces_count; i++)
            {
                putchar(' ');
            } 
            spaces_count = 0;
        } 
                
    }

    return 0;
}
