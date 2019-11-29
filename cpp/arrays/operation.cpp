#include<iostream>
#include<new>
#include<math.h>
using namespace std;

struct Array
{
    int *array;
    int size;
    int length;
};

void setupArray(struct Array *b) {
    b->length = 0;
    b->array = new int[b->size];
}

void printOptions(int length) {
    cout<<"=================================================================="<<endl;
    cout<<"Current length of array is : " << length << endl;
    cout<<"Select following values for the required operations :"<<endl;
    cout<<endl;
    cout<<"=================================================================="<<endl;
    cout<<endl;
    cout<<"enter 1 for Display Array "<<endl;
    cout<<"enter 2 for Add Element in Array "<<endl;
    cout<<"enter 3 for Insert Element in Array "<<endl;
    cout<<"enter 4 for Delete Element in Array "<<endl;
    cout<<"enter 5 for linear Search element in Array "<<endl;
    cout<<"enter 6 for Binary Search element in Array "<<endl;
    cout<<endl;
    cout<<"=================================================================="<<endl;
    cout<<endl;
    return;
}

void displayArray(struct Array *b) {
    int i;
    cout << "=======================Printing-Array==============================" << endl
         << endl;
    for (i = 0; i < b->length; i++)
    {
        cout << "value of array a[" << i << "] :: " << b->array[i] << endl;
    }
    cout << "====================Printing-Array-Done============================" << endl << endl;
    return;
}

void addValue(struct Array *b, int value) {
    if((b->length + 1) > b->size) {
        cout << "Array is full no more values can be added" << endl;
        return;
    }
    b->array[b->length] = value;
    b->length = b->length + 1;
}

void insertValue(struct Array *b, int value, int index) {
    int i;
    if (index < 0 && index > b->length)
    {
        cout << "index can not be greater than length of array" << endl;
        return;
    }

    for (i = b->length - 1; i >= index; i--)
    {
        b->array[i] = b->array[i - 1];
    }

    b->array[index - 1] = value;
    
    return;
}

void deleteElement(struct Array *b, int index) {
    int i;
    if (index > b->length)
    {
        cout << "Index can not be greater than lenght of array" << endl;
        return;
    }

    for (i = index; i < b->length -1; i++)
    {
        b->array[i] = b->array[i + 1];
    }
    b->length = b->length - 1;
    return;
}

int linearSearchArray(struct Array *b, int value) {
    int i;
    for (i = 0; i < b->length; i++)
    {
        if(b->array[i] == value) {
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

int linearSearchArrayWithTranspostion(struct Array *b, int value) {
    int i, temp;
    for (i = 0; i < b->length; i++)
    {
        if(b->array[i] == value) {
            if(i-1 > 0) {
                swapIndexValue(b->array, i, i - 1);
            }

            return (i-1 > 0) ? i-1 : 0;
        }
    }
    return -1;
}

int linearSearchArrayWithMoveToHead(struct Array *b, int value) {
    int i, temp;
    for (i = 0; i < b->length; i++)
    {
        if(b->array[i] == value) {
            swapIndexValue(b->array, i, 0);
            return 0;
        }
    }
    return -1;
}

void bubbleSort(int *array, int length) {
    int i, j;
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++) {
            if(array[j] > array[j+1]) {
                swapIndexValue(array, j+1, j);
            }
        }
    }
    
}

int binarySearchArray(struct Array *b, int value) {
    int l=0, h=b->length-1, mid=(b->length-1)/2;
    bubbleSort(b->array, b->length);
    while (l <= h)
    {
        if(b->array[mid] == value) {
            return mid;
        }
        else if (b->array[mid] > value) {
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

int main(int argc, char const *argv[])
{
    int o, value, index;
    struct Array a;
    cout << "Enter the size of array" << endl;
    cin >> a.size;
    setupArray(&a);
    cout << "you entered size " << a.size << endl;

    while (1)
    {
        printOptions(a.length);
        cin >> o;
        switch (o)
        {
        case 1:
            displayArray(&a);
            break;
        case 2:
            cout << "Enter the value that needs to be added" << endl;
            cin >> value;
            addValue(&a, value);
            break;
        case 3:
            cout << "Enter the value that needs to be inserted" << endl;
            cin >> value;
            cout << "Enter the index position where value needs to inserted" << endl;
            cin >> index;
            insertValue(&a, value, index);
            break;
        case 4:
            cout << "Enter the index position where value needs to deleted" << endl;
            cin >> index;
            deleteElement(&a, index);
            break;
        case 5:
            cout << "Enter the value you want to element" << endl;
            cin >> value;
            cout << "index for key " << value << " is " << linearSearchArray(&a, value) << endl;
            cout << "index for key " << value << " is " << linearSearchArrayWithTranspostion(&a, value) << endl;
            cout << "index for key " << value << " is " << linearSearchArrayWithMoveToHead(&a, value) << endl;
            break;
        case 6:
            cout << "Enter the value you want to element" << endl;
            cin >> value;
            cout << "index for key " << value << " is " << binarySearchArray(&a, value) << " calculated using binarSearch"<< endl;

        default:
            goto exit_loop;
            break;
        }
    }
    
exit_loop:
    if(a.array !=NULL) {
        cout << "cleaning array" << endl;
        delete a.array;
    }
    return 0;
}
