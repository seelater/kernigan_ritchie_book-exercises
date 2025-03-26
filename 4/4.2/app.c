#include <stdio.h>
#include <ctype.h>


double atof(char []);




int main(void)
{
    char test[]="-1245.33E-5";
        double  atof(char []);
        printf("%f",atof(test));

    return 0;
}


double atof(char s [])
{
    double val, power;
    int i, sign;
    char e='0';
    int e_power=1;

    for(i = 0; isspace(s[i]); i++ ) /* пропуск пробелов */
        ;
    sign = (s[i] =='-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] =='.')
        i++;

    for (power = 1.0; isdigit(s[i]) ; i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if(s[i]=='e'||s[i]=='E' ){
        i++;
        if(s[i] == '-'){
            e = '-';
            i++;
        }
    }
    while( s[i]-- > '0' )
    {
       e_power *= 10;
    }


    return (e == '-') ? (sign * val / power )/ e_power:  (sign * val / power) * e_power;
}
