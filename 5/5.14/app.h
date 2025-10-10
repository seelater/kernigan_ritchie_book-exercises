void my_qsort(void *v[],int left, int right,
    int (*comp)(void *, void *));

void swap(void *v[],int i, int j);

int readlines(char *lineptr[], char *mem, int maxlines);

void writelines(char *lineptr[],int nlines,int reverse);

int my_getline(char *s, int lim);


