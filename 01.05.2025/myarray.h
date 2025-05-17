#include <iostream>

int* allocateArray(int size);

void initArrayRandom(int* arr, int size, int minVal = 0, int maxVal = 100);

void printArray(const int* arr, int size);

void freeArray(int*& arr);

void addElementToFront(int*& arr, int& size, int element);

void addElementToEnd(int*& arr, int& size, int element);

void insertElementAt(int*& arr, int& size, int index, int element);

void removeElementFromFront(int*& arr, int& size);

void removeElementFromEnd(int*& arr, int& size);

void removeElementAt(int*& arr, int& size, int index);




int* allocateArray(int size)
{
    if (size <= 0) return nullptr;
    return new int[size];
}

void initArrayRandom(int* arr, int size, int minVal, int maxVal)
{
    if (!arr || size <= 0) return;
    std::srand(std::time(nullptr));
    for (int i = 0; i < size; i++)
        arr[i] = minVal + std::rand() % (maxVal - minVal + 1);
}

void printArray(const int* arr, int size)
{
    if (!arr || size <= 0) return;
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void freeArray(int*& arr)
{
    delete[] arr;
    arr = nullptr;
}

void addElementToFront(int*& arr, int& size, int element)
{
    int* newArr = new int[size + 1];
    newArr[0] = element;
    for (int i = 0; i < size; i++)
        newArr[i + 1] = arr[i];
    delete[] arr;
    arr = newArr;
    size++;
}

void addElementToEnd(int*& arr, int& size, int element)
{
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    newArr[size] = element;
    delete[] arr;
    arr = newArr;
    size++;
}

void insertElementAt(int*& arr, int& size, int index, int element)
{
    if (index < 0) index = 0;
    if (index > size) index = size;

    int* newArr = new int[size + 1];
    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];

    newArr[index] = element;

    for (int i = index; i < size; i++)
        newArr[i + 1] = arr[i];

    delete[] arr;
    arr = newArr;
    size++;
}

void removeElementFromFront(int*& arr, int& size)
{
    if (size <= 0) return;
    int* newArr = nullptr;
    if (size > 1)
    {
        newArr = new int[size - 1];
        for (int i = 1; i < size; i++)
            newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

void removeElementFromEnd(int*& arr, int& size)
{
    if (size <= 0) return;
    int* newArr = nullptr;
    if (size > 1)
    {
        newArr = new int[size - 1];
        for (int i = 0; i < size - 1; i++)
            newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

void removeElementAt(int*& arr, int& size, int index)
{
    if (size <= 0) return;
    if (index < 0) index = 0;
    if (index >= size) index = size - 1;

    int* newArr = nullptr;
    if (size > 1)
    {
        newArr = new int[size - 1];
        for (int i = 0; i < index; i++)
            newArr[i] = arr[i];
        for (int i = index + 1; i < size; i++)
            newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}