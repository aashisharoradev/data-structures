#include<stdio.h>

double exponent(int x , int n) {
    static double sum = 1;
    if( n == 0 ) {
        return sum;
    }
    
    sum = 1 + (double)x/n * sum;

    return exponent(x, n - 1);
}

double e(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if( n == 0 )
        return 1;
    
    r = e(x, n-1);
    p = p * x;
    f = f * n;
    return r + p/f;
}

int main(int argc, char const *argv[])
{
    printf("%lf \n", e(1, 10));
    printf("exponent  %lf \n", exponent(1, 10));
    return 0;
}
