#include<iostream>
using namespace std;

double exponent(int x, int n) {
    static double sum = 1;
    if(n == 0) {
        return sum;
    }

    sum = 1 + (double)x/n * sum;
    return exponent(x, n - 1);
}

double e(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;

    r = e(x , n-1);
    p = p * x;
    f = f * n;

    return r + p / f;
}
int main(int argc, char const *argv[])
{
    cout << "exponent of 1 with number 10 " << e(1, 10) << endl;
    cout << "exponent of 1 with number 10 " << exponent(1, 10) << endl;
    return 0;
}
