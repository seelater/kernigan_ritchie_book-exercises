#include <stdio.h>

#define SIZE 1000
/*   */
void escape(char s[],char t[])
{
    int i,j;
    j=0;
    i=0;
    while (t[i] != '\0')
    {

        switch (t[i])
        {
            case '\n' :
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t' :
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++]=t[i];
                break;
        }
        i++;
    }
    s[i]='\0';
}

int main(void)
{
    char to[SIZE];

    char from[]="HELLo\n world\t hihi\n\thihi";
    escape(to,from); 
    printf("%s\n",to);

    return 0;
}


