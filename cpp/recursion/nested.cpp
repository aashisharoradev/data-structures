#include<iostream>

int printNum(int n) {
    if( n > 0) {
        std::cout<<n;
        return printNum(printNum(n - 1));
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    printNum(95);
    std::cout<<std::endl;
    return 0;
}
