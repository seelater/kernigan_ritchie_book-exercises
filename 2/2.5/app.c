#include <stdio.h>

int any(char [],char []);

int main(void)
{
    
    char test1[]="nnnabcdefgloleee";
    char test2[]="ztasdbz";

    printf("%d\n",any(test1,test2));
    return 0;
}

/* return first pos in s1 if match elem in s2  */
int any(char s1[], char s2[])
{
    int i,j;
    for ( i = 0; s1[i]!='\0';i++)
    {
        for ( j =0; s2[j]!='\0';j++)
        {
            if (s1[i]==s2[j])
            {
                return i;
            }
        }
     }

    return -1;
}
