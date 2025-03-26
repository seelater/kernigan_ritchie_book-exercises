#include <stdio.h>
#include <string.h>


void reverse(char s[])
{
    int c, i, j ;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i] ;
        s[i] = s[j] ;
        s[j] = c;
    }
}

/*example
 *-2147483648 - не поместится в инт при переводе его в положительное 
 * 2147483647
 *
 * */

void itoa(int n, char s[])
{
    int i;
    char sign;
    if(n <0){
        sign = '-';/* записываем знак */
        n= n+1;
        n = -n;
    }
    i = 0;
    do { /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0'; /* извлекаем цифру */
    } while ((n /= 10) > 0); /* удаляем ее */

    if (sign =='-')
    {
        s[i++] = '-';
        s[0]++;
    }
    s[i] = '\0';
    reverse(s);
}


int main(void)
{
    int a = -2147483648;
    int b =  2147483647;

    char s[50];
    itoa(b,s);
    printf("%s\n",s);
    itoa(a,s);
    printf("%s\n",s);
    
    return 0;
}
