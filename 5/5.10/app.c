#include <stdio.h>
#include <stdlib.h> /* for atof()*/

#define MAXOP 100 /*MAX operand or sign size*/
#define NUMBER '0' /*signal that digit discovered*/

int getop(char s[]);
void push(double);
double pop(void);

void ungetch(char *);

/*calc reverse polish */
int main(int argc, char* argv[])
{
    char s[MAXOP];
    double op2;

    while ( --argc > 0 )
    {
        ungetch("");
        ungetch(*++argv);
        switch (getop(s)) {
            case NUMBER: 
                push(atof(s));
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
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
    printf("%.1f\n",pop());

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
void ungetch(char *);

/* извлекает следующий операнд или знак операции*/
int getop(char s[])
{
    int c,i;

    while ( (s[0] = c = getch())== ' ' || c == '\t' )
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' )
        return c;  /*not a number*/
    i=0;

    if (isdigit(c)) /* накопление целой части */
        while (isdigit(s[++i]=c=getch()))
            ;
    if (c=='.')  /* накопление дробной части */
        while (isdigit(s[++i]=c=getch()))
            ;
    s[i]='\0';
    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE]; /* ungetch  buffer*/
int bufp = 0;

int getch(void)
{
    return (bufp>0)? buf[--bufp]: getchar();
}

void ungetch(char* c)
{
    if (bufp>=BUFSIZE)
        printf("error: too many characters\n");
    else
        buf[bufp++]=*c;
}

