#include <stdio.h>
void functionB(int n); // as functionB is used before declaration, so compiler to understand we need write prototype for this
void functionA(int n)
{
    if(n > 0) {
        printf("%d ", n);
        functionB(n -1 );
    }
}

void functionB(int n) {
    if (n > 1) {
        printf("%d ", n);
        functionA(n/2);
    }
}

int main(int argc, char const *argv[])
{
    functionA(20);
    printf("\n");
    return 0;
}
