#include "myarray.h"


int main()
{
    int size = 5;
    int* arr = allocateArray(size);
    initArrayRandom(arr, size, 1, 50);
    printArray(arr, size);

    addElementToFront(arr, size, 100);
    printArray(arr, size);

    addElementToEnd(arr, size, 200);
    printArray(arr, size);

    insertElementAt(arr, size, 3, 999);
    printArray(arr, size);

    removeElementFromFront(arr, size);
    printArray(arr, size);

    removeElementFromEnd(arr, size);
    printArray(arr, size);

    removeElementAt(arr, size, 2);
    printArray(arr, size);

    freeArray(arr);
}
