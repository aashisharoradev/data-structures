#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[5];
    int b[] = {2, 4, 6, 8, 10};
    int c[10] = {1, 3, 5, 7, 9};
    int length = sizeof(b) / sizeof(int), i=0;
    cout << "================style1===============" << endl;
    while (i < length)
    {
        cout << b[i] << endl;
        i++;
    }
    i = 0;
    cout << "================style2===============" << endl;
    while (i < length)
    {
        cout << i[b] << endl;
        i++;
    }
    length = sizeof(c) / sizeof(int);
    i = 0;
    cout << "================style3===============" << endl;
    while (i < length)
    {
        cout << *(c+i) << endl;
        i++;
    }


    return 0;
}
