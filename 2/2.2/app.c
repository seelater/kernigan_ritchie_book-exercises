#include <stdio.h>


int main()
{
    /* analog for
    for (i=0; i<lim-l && (c=getchar()) != ' \n' && с != EOF; ++i)
        s[i] = c;
        */

    int i;
    for(i=0; i<lim-1;++i)
    {
        if((c=getchar()) !='\n' )
        {
            if(c !=EOF)
            {
                s[i]=c;
            }
        }
    }
    


    return 0;
}
