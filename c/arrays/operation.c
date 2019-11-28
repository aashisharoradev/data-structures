#include<stdio.h>
#include<stdlib.h>

void createArray(int **b, int size) {
    if(*b == NULL) {
        printf("making sure array size is 0 \n");
        *b = (int *) malloc(size * sizeof(int *));
    }
    return;
}

void printOptions(int length) {
    printf("================================================================== \n");
    printf("Current length of array is : %d\n", length);
    printf("Select following values for the required operations : \n");
    printf("\n");
    printf("================================================================== \n");
    printf("\n");
    printf("enter 1 for Display Array \n");
    printf("enter 2 for Add in Array \n");
    printf("enter 3 for Insert in Array \n");
    printf("\n");
    printf("================================================================== \n");
    printf("\n");
    return;
}

void displayArray(int *arrayValue, int length) {
    int i;
    printf("=======================Printing-Array============================== \n\n");
    for (i = 0; i < length; i++)
    {
        printf("value of array a[%d] :: %d \n", i, i[arrayValue]);
    }
    printf("====================Printing-Array-Done============================ \n\n");
    return;
}

void addArray(int *arrayValue, int *length, int value, int size) {
    if((*length + 1) > size) {
        printf("New record can not be added as size is %d \n", size);
        return;
    }
    arrayValue[*length] = value;
    *length = *length + 1;
    return;
}

void insertArray(int *arrayValue, int *length, int value, int index) {
    int i = 0;

    for (i = (*length-1); i >= index; i--)
    {
        arrayValue[i] = arrayValue[i-1];
    }
    arrayValue[index-1] = value;
    return;
}

int main(int argc, const char *argv[]) {
    int *a;
    int length = 0, size=0, i, o=100, value, index;
    printf("Enter the size of array you want to create \n");
    scanf(" %d", &size);
    createArray(&a ,size);
    
    while (1)
    {
        printOptions(length);
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            displayArray(a, length);
            break;
        case 2:
            printf("Enter the value you want to add \n");
            scanf("%d", &value);
            if(value > 0) {
                addArray(a, &length, value, size);
            }
            break;
        case 3:
            printf("Enter the value you want to insert \n");
            scanf("%d", &value);
            printf("Enter index where you want to insert \n");
            scanf("%d", &index);
            if(value > 0 && index < size) {
                insertArray(a, &length, value, index);
            }
            break;
        default:
            goto exit_loop;
            break;
        }
    }
    
exit_loop:

    if(a != NULL) {
        printf("cleaning up array \n");
        free(a);
        a = NULL;
    }
    return 0;

}


