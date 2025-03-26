#include <stdio.h>

#define MAXLINE 1000

int getline(char line[],int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int pos=0;

    while (getline(line,MAXLINE) > 0)
        if ( (pos= strindex(line,pattern)) >= 0){
            printf("pos =%d %s",pos,line);
            found++;
        }
    return found;
}

/* считавает строку в s возвращаяет её длинну  */
int getline(char s[], int lim)
{
    int c,i;

    i=0;
    while (--lim > 0 && (c = getchar())!=EOF && c != '\n' )
        s[i++]=c;
    if (c == '\n')
        s[i++] =c;
    s[i] = '\0';
    return i;

}

/* возвращает индекс строки s  в t или -1 при отсутствии  */
int strindex(char s[],char t[])
{
    int i,j,k,count;
    count =0;
    int pos=0;

    for (i=0; s[i] != '\0'; i++){
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++,k++)
            ;
        if (k>0 && t[k] == '\0'){
            count++;
            pos=j;
        }
    }
    return (count !=0 ) ? pos-4 : -1;

}


