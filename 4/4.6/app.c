#include <stdio.h>
#include <stdlib.h> /* for atof()*/

#define MAXOP 100 /*MAX operand or sign size*/
#define NUMBER '0' /*signal that digit discovered*/
#define ABC_SIZE 26;
#define VAR 'A'

int getop(char s[]);
void push(double);
double pop(void);

/*calc reverse polish */
int main(void)
{
    char s[MAXOP];
    int type;
    double op2;
    double abc[ABC_SIZE];
    int i;
    for(i=0; i<ABC_SIZE;i++)
    {
        abc[i]=0.0;
    }


    while ( (type = getop(s)) != EOF )
    {
        if(type >= 'A' && type <= 'Z')
        {
            VAR=type;
        }
        switch (type) {
            case NUMBER: 
                push(atof(s));
                break;
            case VAR:
                abc[VAR-'A']=pop();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2=pop();
                push(pop() - op2);
                break;
            case '/':
                op2=pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else    
                    printf("error: zero divisor\n");
                break;
            case '%':
                    op2=pop();
                    push((int)pop() % (int)op2);
                    break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;                
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }

    return 0;
}

#define MAXVAL 100 /*stack max depth */

int sp = 0; /* stack index*/
double val[MAXVAL];

/*push*/
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n ",f);
}

/*pop*/
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* извлекает следующий операнд или знак операции*/
int getop(char s[])
{
    int c,i;

    while ( (s[0] = c = getch())== ' ' || c == '\t' )
        ;        
    s[1] = '\0';

    if(c >='A' && c >='Z')
    {
        return c;
    }


    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;  /*not a number*/
    }
    i=0;

    if (c == '-')
    {
        if ( isdigit(c=getch()) || c == '.')
        {
            s[++i]=c;
        }else{
            if ( c != EOF)
                ungetch(c);
            
            return '-';
        }
    }

    if (isdigit(c)) /* накопление целой части */
        while (isdigit(s[++i]=c=getch()))
               ;
    if (c=='.')  /* накопление дробной части */
        while (isdigit(s[++i]=c=getch()))
            ;
    s[i]='\0';
    if (c != EOF)
        ungetch(c);

   
    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE]; /* ungetch  buffer*/
int bufp = 0;

int getch(void)
{
    return (bufp>0)? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if (bufp>=BUFSIZE)
        printf("error: too many characters\n");
    else
        buf[bufp++]=c;
}

