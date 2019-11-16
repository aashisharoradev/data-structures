#include<stdio.h>

void towerOfHanoi(int numnberOfRings, int a, int b, int c) {
    if(numnberOfRings > 0) {
        towerOfHanoi(numnberOfRings - 1, a, c, b);
        printf("moving ring from tower %d  to %d \n", a, c);
        towerOfHanoi(numnberOfRings - 1, b, a, c);
    }
    
}

int main(int argc, char const *argv[])
{
    towerOfHanoi(3, 1, 2, 3);
    return 0;
}
