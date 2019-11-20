#include<iostream>
#include <new>

using namespace std;

int main(int argc, char const *argv[])
{
    int *p = new int[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        p[i] = 2*(i+1);
    }

    for (i = 0; i < 5; i++)
    {
        cout << i[p] << endl;
    }
    delete []p;
    p = NULL;
    return 0;
}
