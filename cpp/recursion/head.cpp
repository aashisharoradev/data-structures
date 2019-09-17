#include<iostream>

using namespace std;

void printNum(int num){
    if(num > 0) {
        printNum(num - 1);
        cout << num;
    }
}

int main(int argc, char const *argv[])
{
    printNum(3);
    cout << endl;
    return 0;
}
