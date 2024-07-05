#include <stdio.h>

int main()
{
    double c=0;
    double temp = 0;

    while( (c=getchar() ) !=EOF   )
    {
        if (c != ' ')
        {
            putchar(c);
            temp = 0;
        }
        if( c == ' ') 
        {
            ++temp;
            if (temp < 2)
            {
                putchar(c);
            }
        }
    }   
    return 0;
}
