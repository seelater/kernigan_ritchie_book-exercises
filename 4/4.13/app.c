#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000

void itoa(int,char []);
void reverse(char []);

int main(void)
{
    int num;
    char str[MAXSIZE];
        
    num = 123456789;

    itoa(num,str);

    printf("%s\n",str);
    printf("%li\n",strlen(str));

    reverse(str);
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


/* reverse: обращает порядок символов в строке s */
void reverse(char s[])
{
    int temp;
    static unsigned int i=0;
    static unsigned int j;
    
    j = strlen(s)- (i+1);

    if ( i < j)
    {
        temp = s[i];
        s[i++]=s[j];
        s[j]=temp;

        reverse(s);
    }
}
