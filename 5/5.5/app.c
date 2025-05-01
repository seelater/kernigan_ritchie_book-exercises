

//копирует не более n символов из t в s
void my_strncpy(char *s,char *t, int n)
{
    while (n-- && *t)
        *s++ = *t++;
    s='\0';
}
//присоединяет n символов из t в хвост s
void my_strncat(char *s, char *t, int n)
{
    while (*s++)
        ;
    s--;
    while (n-- && *t)
        *s++ = *t++;
    s='\0';
}
// дает отрицательное. ноль или положительное число при s<t s == t s>t для первых n симолов строки s

int my_strncmp(char *s, char *t, int n)
{
    while (*s == *t && n){
        s++;
        t++;
        n--;
    }

    if ( n == 0)
        return 0;
    else  if (*s == '\0' && *t)
        return -1;
    else if ( *s && *t == '\0')
        return 1;
    else{
        return *s - *t;
        }
            
    return 0;

    
}

int main(void)
{
    return 0;
}
