#include<iostream>

using namespace std;

int factorial(int num)
{
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
    cout<<"Factorial of 5 " << factorial(5) << endl;
    cout<<"Factorial of 6 "<< factorialLoop(6) << endl;
    return 0;
}
