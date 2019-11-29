#include<iostream>
#include<new>
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
    cout<<"enter 2 for Add in Array "<<endl;
    cout<<"enter 3 for Insert in Array "<<endl;
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
