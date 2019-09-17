#include<iostream>

using namespace std;

int exponent(int base, int power) {
    if (power > 0) {
        return exponent(base, power -1 ) * base;
    }
    return 1;
}

int exponentReduceMultiply(int base, int power) {
    if(power == 0) {
        return 1;
    } else if(power%2 == 0) {
        return exponentReduceMultiply(base * base, power/2);
    } else {
        return base * exponentReduceMultiply(base * base, (power-1)/2);
    }
}



int main(int argc, char const *argv[])
{
    cout << "2 power 8 is " << exponent(2, 8) <<endl;
    cout << "2 power 9 is " << exponentReduceMultiply(2, 9) <<endl;
    return 0;
}
