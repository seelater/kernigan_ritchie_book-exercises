#include <stdio.h>

#define MAXSIZE 1000

void itoa(int,char[]);

int main(void)
{
    int num;
    char str[MAXSIZE];
        
    num = 12345789;

    itoa(num,str);

    printf("%s\n",str);

    return 0;
}


/*int to str
 *recurse
 * */
void itoa(int n, char s[])
{
    static int i=0;
    if(n<0)
    {
        s[i++]='-';
        n=-n;
    }
    if (n/10)
        itoa(n/10,s);
    s[i++]=n % 10 + '0';
    s[i]='\0'; 
}


