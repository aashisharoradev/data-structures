#include<stdio.h>

int printNum(int n) {
    if( n > 0) {
        printf("%d ", n);
        return printNum(printNum(n - 1));
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    printNum(95);
    printf("\n");
    return 0;
}
