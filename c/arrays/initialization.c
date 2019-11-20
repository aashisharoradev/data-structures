#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a[5];  //this will create an array of size 5

    int b[] = {2, 4, 6, 8, 10}; // this will create an array with size 5 having even numbers 2-10

    int length = sizeof(b) / sizeof(int);

    int i = 0;

    // accessing an array
    while (i < length)
    {
        printf("%d :: \n", b[i]);
        i++;
    }
    i = 0;
    // accessing an array using pointer 
    while (i < length)
    {
        printf("%d :: \n",  *(a + i));
        i++;
    }

    return 0;
}
