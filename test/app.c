#include <stdio.h>
/*ads*/
int main()
{

    for (int i=0; i<10;printf("for%d",i++))
    {
        printf("%d",i);
    }
    puts("\n");
    for (int i=0; i<10;printf("for%d",++i))
    {
        printf("inside%d",i);
    }
    puts("\n");
    return 0;

}
