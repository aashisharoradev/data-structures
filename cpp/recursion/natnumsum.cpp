#include<iostream>

using namespace std;

int sum(int n)
{
    return n * (1 + n) / 2;
}

int sumRecursion(int n) {
    if (n > 0)
    {
       return sumRecursion(n - 1) + n;
    }
    return 0;
}

int sumUsingWhile (int n) {
    int sum = 0;
    while (n > 0)
    {
        sum += n;
        n--;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    cout<<"sum using series " << sum(20) << endl;  // o(1)
    cout<<"sum of natural number " << sumRecursion(20) << endl; // o(n)
    cout<<"sum of natural number using while " << sumUsingWhile(20) << endl; // time o(n) space o(1)
    return 0;
}
