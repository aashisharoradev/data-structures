#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void createArray(struct Array *a) {
    a->A = (int *) malloc(a->size * sizeof(int));
    a->length = 0;
    return;
}

void printOptions(struct Array *a) {
    printf("================================================================== \n");
    printf("Current length of array is : %d\n", a->length);
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
    printf("enter 15 for merge Array elements \n");
    printf("\n");
    printf("================================================================== \n");
    printf("\n");
    return;
}

void displayArray(struct Array *a) {
    int i;
    printf("=======================Printing-Array============================== \n\n");
    for (i = 0; i < a->length; i++)
    {
        printf("value of array a[%d] :: %d \n", i, i[a->A]);
    }
    printf("====================Printing-Array-Done============================ \n\n");
    return;
}

void addValue(struct Array *a, int value) {
    if (a->length >= a->size)
    {
        printf("New record can not be added as size is %d \n", a->size);
        return;
    }
    a->A[a->length] = value;
    a->length = a->length + 1;
    return;
}

void insertArray(struct Array *a, int value, int index) {
    int i = 0;
    if (index < 0 && index > a->length)
    {
        printf("index can not be greater than length of array");
        return;
    }
    for (i = (a->length-1); i >= index; i--)
    {
        a->A[i] = a->A[i-1];
    }
    a->A[index-1] = value;
    return;
}

void deleteArray(struct Array *a, int index) {
    int i;
    if (index > a->length) {
        printf("Index can not be greater than lenght of array \n");
        return ;
    }

    for (i = index; i < a->length -1; i++)
    {
        a->A[i] = a->A[i+1];
    }
    a->length = a->length - 1;
    return;
}

int linearSearchArray(struct Array *a, int value) {
    int i;
    for (i = 0; i < a->length; i++)
    {
        if(a->A[i] == value) {
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

void bubbleSort(struct Array *a) {
    int i, j, flag=0;
    for (i = 0; i < a->length - 1; i++)
    {
        for (j = 0; j < a->length -i -1; j++)
        {
            if(a->A[j] > a->A[j+1]) {
                swapIndexValue(a->A, j+1, j);
            }
        }
    }
    
}
int binarySearchArray(struct Array *a, int value) {
    int l=0, h=a->length-1, mid=(a->length-1)/2;
    bubbleSort(a); // for binary array search array needs to be sorted, we sorted array using bubble sort
    displayArray(a);
    while (l <= h)
    {
        if(a->A[mid] == value) {
            return mid;
        }
        else if (a->A[mid] > value) {
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

int linearSearchArrayWithTranspostion(struct Array *a, int value) {
    int i, temp;
    for (i = 0; i < a->length; i++)
    {
        if(a->A[i] == value) {
            if(i-1 > 0) {
                swapIndexValue(a->A, i, i - 1);
            }

            return (i-1 > 0) ? i-1 : 0;
        }
    }
    return -1;
}

int linearSearchArrayWithMoveToHead(struct Array *a, int value) {
    int i, temp;
    for (i = 0; i < a->length; i++)
    {
        if(a->A[i] == value) {
            swapIndexValue(a->A, i, 0);
            return 0;
        }
    }
    return -1;
}

int getElement(struct Array *a, int index) {
    return a->A[index];
}

void setElement(struct Array *a, int value, int index) {
    a->A[index] = value;
}

int max(struct Array *a) {
    int max = a->A[0];
    int i;
    for (i = 1; i < a->length; i++)
    {
        if(max < a->A[i]) {
            max = a->A[i];
        }
    }
    
    return max;
}

int min(struct Array *a) {
    int min = a->A[0];
    int i;
    for (i = 1; i < a->length; i++)
    {
        if(min > a->A[i]) {
            min = a->A[i];
        }
    }
    
    return min;
}

int sum(struct Array *a) {
    int sum = 0;
    int i;
    for (i = 0; i < a->length; i++)
    {
        sum+=a->A[i];
    }
    
    return sum;
}

void reverseArray(struct Array *a) {
    int i;
    for (i = 0; i < a->length/2; i++)
    {
        swapIndexValue(a->A, i, a->length-1-i);
    }
}

bool isArraySorted(struct Array *a) {
    int i;
    for (i = 0; i < a->length; i++)
    {
        if(a->A[i] > a->A[i+1]) {
            return false;
        }
    }
    
    return true;
}

void insertValueSortedArray(struct Array *a, int value) {
    int i;
    bool isSorted = true;
    if (a->length + 1 > a->size)
    {
        printf("Array is full, element can not be inserted");
        return;
    }
    isSorted = isArraySorted(a);
    if (isSorted == false)
    {
        printf("provided array is not sorted \n");
        bubbleSort(a);
    }

    for (i = a->length; i > 0; i--)
    {
        
        if(value > a->A[i-1]) {
            a->A[i] = value;
            break;
        } else {
            a->A[i] = a->A[i - 1];
            a->A[i - 1] = value;
        }
    }
     a->length = a->length + 1;
    
    
}
void cleanup(struct Array *a) {
    if(a->A !=NULL) {
        printf("cleaning up array\n");
        free(a->A);
        a->A = NULL;
    }
}
struct Array* mergeArray(struct Array *a, struct Array *b) {
    int i,j;
    struct Array c;
    c.size = a->length + b->length;
    createArray(&c);
    c.length = a->length + b->length;
    
    for (i = 0; i < a->length; i++)
    {
        c.A[i] = a->A[i];
    }
   
    i = b->length;
    
    for (i=a->length,j=0; i < c.length && j<b->length; i++,j++)
    {
       
        c.A[i] = b->A[j];
    }

    return &c;
}
struct Array* mergeSortedArray(struct Array *a, struct Array *b) {
    int i = 0, j = 0, k=0;
    bool isSorted = true;
    struct Array c;
    isSorted = isArraySorted(a);
    c.size = a->length + b->length;
    if (isSorted == false)
    {
        bubbleSort(a);
    }

    isSorted = true;
    isSorted = isArraySorted(b);

    if(isSorted == false) {
        bubbleSort(b);
    }
    createArray(&c);
    c.length = a->length + b->length;
    while (i < a->length && j < b->length)
    {
        if(a->A[i] < b->A[j]) {
            c.A[k] = a->A[i];
            k++;
            i++;
        }
        else
        {
            c.A[k] = b->A[j];
            k++;
            j++;
        }
    }

    for (; i < a->length;i++) {
        c.A[k] = a->A[i];
        k++;
    }

    for (; j < a->length;j++) {
        c.A[k] = b->A[j];
        k++;
    }

    return &c;
}

struct Array* unionSortedArray(struct Array *a, struct Array *b) {
    int i=0,j=0;
    bool isSorted = true;
    struct Array c;
    isSorted = isArraySorted(a);
    c.size = a->length + b->length;
    if (isSorted == false)
    {
        bubbleSort(a);
    }

    isSorted = true;
    isSorted = isArraySorted(b);

    if(isSorted == false) {
        bubbleSort(b);
    }
    createArray(&c);

    while (i < a->length && j < b->length)
    {
        if(a->A[i] == b->A[j]) {
            c.A[c.length] = a->A[i];
            c.length++;
            i++;
            j++;
        } else if(a->A[i] < b->A[j]) {
            c.A[c.length] = a->A[i];
            c.length++;
            i++;
        }
        else
        {
            c.A[c.length] = b->A[j];
            c.length++;
            j++;
        }
    }
    
    for (; i < a->length; i++)
    {
        c.A[c.length] = a->A[i];
        c.length++;
    }
    
    for (; j < b->length; j++)
    {
        c.A[c.length] = b->A[j];
        c.length++;
    }

    return &c;
}

struct Array* intersectSortedArray(struct Array *a, struct Array *b) {
    int i=0,j=0;
    bool isSorted = true;
    struct Array c;
    isSorted = isArraySorted(a);
    
    if (isSorted == false)
    {
        bubbleSort(a);
    }

    isSorted = true;
    isSorted = isArraySorted(b);

    if(isSorted == false) {
        bubbleSort(b);
    }

    if(a->length > b->length) {
        c.size = a->length;
    }
    else
    {
        c.size = b->length;
    }
    createArray(&c);

    while (i < a->length && j < b->length)
    {
        if(a->A[i] == b->A[j]) {
            c.A[c.length] = a->A[i];
            c.length++;
            i++;
            j++;
        }
        else if(a->A[i] < b->A[j]) {
            i++;
        } else {
            j++;
        }
    }
    return &c;
}

int main(int argc, const char *argv[]) {
    int i, o=100, value, index, len;
    struct Array a;
    struct Array b = {NULL, 0, 0};
    struct Array c;
    printf("Enter the size of array you want to create \n");
    scanf("%d", &(a.size));
    createArray(&a);
    
    while (1)
    {
        printOptions(&a);
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            displayArray(&a);
            break;
        case 2:
            printf("Enter the value you want to add \n");
            scanf("%d", &value);
            if(value >= 0) {
                addValue(&a, value);
            }
            break;
        case 3:
            printf("Enter the value you want to insert \n");
            scanf("%d", &value);
            printf("Enter index where you want to insert \n");
            scanf("%d", &index);
            insertArray(&a, value, index);
            break;
        case 4:
            printf("Enter index where you want to delete \n");
            scanf("%d", &index);
            deleteArray(&a, index);
            break;
        case 5:
            printf("Enter the value you want to element \n");
            scanf("%d", &value);
            printf("index for key %d = %d \n",value, linearSearchArray(&a, value));
            printf("index for key %d = %d \n",value, linearSearchArrayWithTranspostion(&a, value));
            printf("index for key %d = %d \n",value, linearSearchArrayWithMoveToHead(&a, value));
            break;
        case 6:
            printf("Enter the value you want to element \n");
            scanf("%d", &value);
            printf("index for key %d = %d \n",value, binarySearchArray(&a, value));
            break;
        case 7:
            printf("Enter the index for which you want an element \n");
            scanf("%d", &index);
            if(index < 0 && index > a.length) {
                printf("Invalid Index \n");
            } else {
                printf("Element at index %d is %d \n", index, getElement(&a, index));
            }
            break;
        case 8:
            printf("Enter the index for which you want an element");
            scanf("%d", &index);
            printf("Enter the Element value");
            scanf("%d", &value);
            if(index < 0 && index > a.length) {
                printf("Invalid Index");
            } else {
                setElement(&a, value, index);
            }
            break;
        case 9:
            printf("Max Element of Array is %d \n", max(&a));
            break;
        case 10:
            printf("Min Element of Array is %d \n", min(&a));
            break;
        case 11:
            printf("Sum Of all Elementf of Array is %d \n", sum(&a));
            break;
        case 12:
            printf("Avg of all Elements of Array is %lf \n", (double)(sum(&a)/a.length));
            break;
        case 13:
            reverseArray(&a);
            break;
        case 14:
            printf("Enter the Element value\n");
            scanf("%d", &value);
            insertValueSortedArray(&a, value);
            break;
        case 15:
            printf("Enter the size of Array you want to merge \n");
            scanf("%d", &b.size);
            createArray(&b);
            for (i = 0; i < b.size; i++)
            {
                printf("enter value \n");
                scanf("%d", &value);
                addValue(&b, value);
            }
            c = *mergeArray(&a, &b);
            displayArray(&c);
            cleanup(&c);
            c = *mergeSortedArray(&a, &b);
            displayArray(&c);
            cleanup(&c);
            c = *unionSortedArray(&a, &b);
            displayArray(&c);
            cleanup(&c);
            c = *intersectSortedArray(&a, &b);
            displayArray(&c);
            break;
        default:
            goto exit_loop;
            break;
        }
    }
    
exit_loop:
    cleanup(&a);
    cleanup(&b);
    cleanup(&c);
    return 0;
}


