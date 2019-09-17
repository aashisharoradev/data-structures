#include<iostream>

using namespace std;

void printNum(int num){
    if(num > 0) {
        cout << num;
        printNum(num - 1);
    }
}

int main(int argc, char const *argv[])
{
    printNum(3);
    cout << endl;
    return 0;
}
