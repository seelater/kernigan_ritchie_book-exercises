#include <stdio.h>

void squeeze_alt(char [],char []);

int main(void)
{
    
    char test1[]="abcdefgloleee";
    char test2[]="badflolkek";

    squeeze_alt(test1,test2);
    return 0;
}

/* remove all same symbols that contains in s2 from s1*/
void squeeze_alt(char s1[], char s2[])
{
    int i,j,k;
    k=0;
    int count=0;
    for ( i = 0; s1[i]!='\0';i++)
    {
        for ( j =0; s2[j]!='\0';j++)
        {
            if (s1[i]==s2[j])
            {
                count++;
                break;
            }
        }

        if(count == 0)
        {
            s1[k++]=s1[i];
        }
        count =0;
    }
    s1[k]='\0';
    printf("%s\n",s1);
    
}
