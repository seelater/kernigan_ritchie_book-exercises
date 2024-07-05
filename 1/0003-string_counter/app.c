#include <stdio.h>

int main()
{
    /*
     *@nl new_line
     *
     */
    int c=0;
    double nl=0;
    
    while ((c = getchar())!=EOF)
    {
        if ( c == '\n')
        {
            ++nl;
        }
    }
    printf("%.0f\n",nl);
    return 0;
}
