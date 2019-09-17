#include<stdio.h>

int fibSeries[10];

int printSeries(int n) {
   
    if(n <= 1) {
        fibSeries[n] = n;
        return n;
    }
    
        fibSeries[n-2] = printSeries(n - 2);
   
    
        fibSeries[n-1] = printSeries(n - 1);
   
    
    return fibSeries[n-1] + fibSeries[n - 2];
}

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < sizeof(fibSeries)/sizeof(int); i++)
    {
        fibSeries[i] = -1;
    }
    printSeries(10);
    for (i = 0; i < sizeof(fibSeries)/sizeof(int); i++)
    {
        printf("%d ", fibSeries[i]);
    }
    
    return 0;
}
