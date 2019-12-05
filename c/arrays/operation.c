#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>

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
    printf("enter 2 for Add Element in Array \n");
    printf("enter 3 for Insert Element in Array \n");
    printf("enter 4 for Delete element in Array \n");
    printf("enter 5 for linear Search element in Array \n");
    printf("enter 6 for Binary Search element in Array \n");
    printf("enter 7 for get element in Array \n");
    printf("enter 8 for set element in Array \n");
    printf("enter 9 for maximum element in Array \n");
    printf("enter 10 for minimum element in Array \n");
    printf("enter 11 for sum of all elements in Array \n");
    printf("enter 12 for average of all elements in Array \n");
    printf("enter 13 for reversing array elements \n");
    printf("enter 14 for insert in sorted array elements \n");
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

void addValue(int *arrayValue, int *length, int value, int size) {
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
    if (index < 0 && index > *length)
    {
        printf("index can not be greater than length of array");
        return;
    }
    for (i = (*length-1); i >= index; i--)
    {
        arrayValue[i] = arrayValue[i-1];
    }
    arrayValue[index-1] = value;
    return;
}

void deleteArray(int *arrayValue, int *length, int index) {
    int i;
    if (index > *length) {
        printf("Index can not be greater than lenght of array \n");
        return ;
    }

    for (i = index; i < *length -1; i++)
    {
        arrayValue[i] = arrayValue[i+1];
    }
    *length = *length - 1;
    return;
}

int linearSearchArray(int *arrayValue, int value, int length) {
    int i;
    for (i = 0; i < length; i++)
    {
        if(arrayValue[i] == value) {
            return i;
        }
    }
    return -1;
}

void swapIndexValue(int *arrayValue, int sourceIndex, int targetIndex) {
    int temp;
    temp = arrayValue[sourceIndex];
    arrayValue[sourceIndex] = arrayValue[targetIndex];
    arrayValue[targetIndex] = temp;
    return;
}

void bubbleSort(int *arrayValue, int length) {
    int i, j, flag=0;
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length -i -1; j++)
        {
            if(arrayValue[j] > arrayValue[j+1]) {
                swapIndexValue(arrayValue, j+1, j);
            }
        }
    }
    
}
int binarySearchArray(int *arrayValue, int value, int length) {
    int l=0, h=length-1, mid=(length-1)/2;
    bubbleSort(arrayValue, length); // for binary array search array needs to be sorted, we sorted array using bubble sort
    displayArray(arrayValue, length);
    while (l <= h)
    {
        if(arrayValue[mid] == value) {
            return mid;
        }
        else if (arrayValue[mid] > value) {
            h = mid - 1;
            mid = floor((h + l) / 2);
        }
        else {
            l = mid + 1;  
            mid = ceil((h + l) / 2);
        }
    }
    return -1;
}

int linearSearchArrayWithTranspostion(int *arrayValue, int value, int length) {
    int i, temp;
    for (i = 0; i < length; i++)
    {
        if(arrayValue[i] == value) {
            if(i-1 > 0) {
                swapIndexValue(arrayValue, i, i - 1);
            }

            return (i-1 > 0) ? i-1 : 0;
        }
    }
    return -1;
}

int linearSearchArrayWithMoveToHead(int *arrayValue, int value, int length) {
    int i, temp;
    for (i = 0; i < length; i++)
    {
        if(arrayValue[i] == value) {
            swapIndexValue(arrayValue, i, 0);
            return 0;
        }
    }
    return -1;
}

int getElement(int *arrayValue, int index) {
    return arrayValue[index];
}

void setElement(int *arrayValue, int value, int index) {
    arrayValue[index] = value;
}

int max(int *arrayValue, int length) {
    int max = arrayValue[0];
    int i;
    for (i = 1; i < length; i++)
    {
        if(max < arrayValue[i]) {
            max = arrayValue[i];
        }
    }
    
    return max;
}

int min(int *arrayValue, int length) {
    int min = arrayValue[0];
    int i;
    for (i = 1; i < length; i++)
    {
        if(min > arrayValue[i]) {
            min = arrayValue[i];
        }
    }
    
    return min;
}

int sum(int *arrayValue, int length) {
    int sum = 0;
    int i;
    for (i = 0; i < length; i++)
    {
        sum+=arrayValue[i];
    }
    
    return sum;
}

void reverseArray(int *arrayValue, int length) {
    int i;
    for (i = 0; i < length/2; i++)
    {
        swapIndexValue(arrayValue, i, length-1-i);
    }
}

bool isArraySorted(int *arrayValue, int length) {
    int i;
    for (i = 0; i < length; i++)
    {
        if(arrayValue[i] > arrayValue[i+1]) {
            return false;
        }
    }
    
    return true;
}

void insertValueSortedArray(int *arrayValue, int value, int length) {
    int i;
    bool isSorted = isArraySorted(arrayValue, length);
    
    if(isSorted == false) {
        printf("provided array is not sorted \n");
        bubbleSort(arrayValue, length);
    }

    for (i = length; i > 0; i--) 
    {
        if(value > arrayValue[i-1]) {
            arrayValue[i] = value;
            break;
        } else {
            arrayValue[i] = arrayValue[i-1];
        }
    }
    
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
                addValue(a, &length, value, size);
            }
            break;
        case 3:
            printf("Enter the value you want to insert \n");
            scanf("%d", &value);
            printf("Enter index where you want to insert \n");
            scanf("%d", &index);
            insertArray(a, &length, value, index);
            break;
        case 4:
            printf("Enter index where you want to delete \n");
            scanf("%d", &index);
            deleteArray(a, &length, index);
            break;
        case 5:
            printf("Enter the value you want to element \n");
            scanf("%d", &value);
            printf("index for key %d = %d \n",value, linearSearchArray(a, value, length));
            printf("index for key %d = %d \n",value, linearSearchArrayWithTranspostion(a, value, length));
            printf("index for key %d = %d \n",value, linearSearchArrayWithMoveToHead(a, value, length));
            break;
        case 6:
            printf("Enter the value you want to element \n");
            scanf("%d", &value);
            printf("index for key %d = %d \n",value, binarySearchArray(a, value, length));
            break;
        case 7:
            printf("Enter the index for which you want an element");
            scanf("%d", &index);
            if(index < 0 && index > length) {
                printf("Invalid Index");
            } else {
                printf("Element at index %d is %d", index, getElement(a, index));
            }
        case 8:
            printf("Enter the index for which you want an element");
            scanf("%d", &index);
            printf("Enter the Element value");
            scanf("%d", &value);
            if(index < 0 && index > length) {
                printf("Invalid Index");
            } else {
                setElement(a, value, index);
            }
            break;
        case 9:
            printf("Max Element of Array is %d \n", max(a, length));
            break;
        case 10:
            printf("Min Element of Array is %d \n", min(a, length));
            break;
        case 11:
            printf("Sum Of all Elementf of Array is %d \n", sum(a, length));
            break;
        case 12:
            printf("Avg of all Elements of Array is %lf \n", (double)(sum(a, length)/length));
            break;
        case 13:
            reverseArray(a, length);
            break;
        case 14:
            printf("Enter the Element value\n");
            scanf("%d", &value);
            insertValueSortedArray(a, value, length);
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


