#include<stdio.h>

int sum(int n) {
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
    printf("sum using series %d \n", sum(20));  // o(1)
    printf("sum of natural number %d \n", sumRecursion(20)); // o(n)
    printf("sum of natural number using while %d", sumUsingWhile(20)); // time o(n) space o(1)
    return 0;
}
