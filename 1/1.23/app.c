#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c=0;
    int slash = 0;
    int star = 0;
    int  state = OUT;

    while ( (c = getchar())!= EOF ) {
        
        if (state == OUT)
        {
            if (c == '/'){
                slash = 1;
            }else if ( (slash == 1) && (c == '*') )
            {
                star = 1;
                state = IN;
            }else if(c != '\n')
            { 
                slash = 0;
                putchar(c);
            }
        }
                  
        if (state == IN ) {
            if (c == '*')
            {
                star = 0;
            }else if (c == '/' && star == 0){
                state = OUT;
            }
        }
      

   }
    
    puts("");
    return 0;
}
