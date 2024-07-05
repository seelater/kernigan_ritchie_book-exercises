#include <stdio.h>


int main ()
{
    long char_count = 0;
    
    while (getchar() != EOF)
    {
        ++char_count;
    }
      
    printf("%ld\n",char_count);
    
    return 0;    
}
