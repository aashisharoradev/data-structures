#include <iostream>
using namespace std;
void functionB(int n); // as functionB is used before declaration, so compiler to understand we need write prototype for this
void functionA(int n)
{
    if(n > 0) {
        cout << n;
        functionB(n -1 );
    }
}

void functionB(int n) {
    if (n > 1) {
        cout << n;
        functionA(n/2);
    }
}

int main(int argc, char const *argv[])
{
    functionA(20);
    cout << endl;
    return 0;
}
