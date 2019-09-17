#include<stdio.h>

void printNum(int num){
    if (num > 0)
    {
        printNum(num - 1);
        printf("%d", num);
    }
}

int main(int argc, char const *argv[])
{
    printNum(3);
    printf("\n");
    return 0;
}
