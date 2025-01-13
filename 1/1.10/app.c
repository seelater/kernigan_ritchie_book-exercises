#include <stdio.h>


int main()
{
    double c = 0;
    while ( (c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }else if (c == '\b') 
        {
            printf("\\b");
        }else if (c == '\\') 
        {
            printf("\\\\ ");
        }else{
            putchar(c);
        }
   }
    return 0;
}
