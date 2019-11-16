#include<iostream>

using namespace std;

void towerOfHanoi(int numberOfRings, int a, int b, int c) {
    if(numberOfRings > 0) {
        towerOfHanoi(numberOfRings - 1, a, c, b);
        cout << "moving ring from " << a << " to " << c << endl;
        towerOfHanoi(numberOfRings - 1, b, a, c);
    }
}

int main(int argc, char const *argv[])
{
    towerOfHanoi(5, 1, 2, 3);
    return 0;
}
