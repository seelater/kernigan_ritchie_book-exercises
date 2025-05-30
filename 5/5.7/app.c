
#define MAXLINES 5000
#define MAXLEN 1000
int getline(char *, int);

#define ALLMAXLEN MAXLINES * MAXLEN

int readlines(char *lineptr[], int maxlines)
{

    int len,nlines;
    char line[MAXLEN];

    char allline[ALLMAXLEN];
    // первый элемент массива
    char *pstart = allline;
    // последний элемент массива
    char *pend = allline + ALLMAXLEN;

    nlines = 0;
    while( (len = getline(line,MAXLEN)) > 0 )
        if (nlines >= maxlines||  len + pstart > pend)
            return -1;
        else {
            line[len-1]='\0';
            strcpy(pstart,line);
            lineptr[nlines++] = pstart;
            pstart+=len;
        }
    return nlines;   

}

int main(void){return 0;}
