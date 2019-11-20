#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int *p;
    int i=0;
    p = (int *)malloc(5 * sizeof(int));  // this will create an array inside heap
    for (i = 0; i < 5; i++)
    {
        p[i] = 2*(i+1);
    }

    for (i = 0; i < 5; i++)
    {
       printf("%d \n", p[i]);
    }
    
    free(p);
    p = NULL;
    return 0;
}
