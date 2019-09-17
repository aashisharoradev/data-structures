#include<stdio.h>

void printNum(int num){
    if(num > 0) {
        printf("%d", num);
        printNum(num - 1);
        printNum(num - 1);
    }
}

int main(int argc, char const *argv[])
{
    printNum(3);
    printf("\n");
    return 0;
}
