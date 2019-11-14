#include<stdio.h>

int factorial(int num) {
    if(num > 0) {
        return factorial(num - 1) * num;
    }
    
    return 1;
}

int factorialLoop(int num) {
    int factorial = 1;
    while (num >= 1)
    {
        factorial *= num;
        num--;
    }
    return factorial;
}

int main(int argc, char const *argv[])
{
    printf("Factorial of 5 %d\n", factorial(5));
    printf("Factorial of 6 %d", factorialLoop(6));
    return 0;
}
