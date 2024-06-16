#include <iostream>
#include <stdlib.h>

using namespace std;

void getMaxMin(const int *pArray, int &max, int &min, int size);

int main()
{
    int size;
    int *pArray = nullptr;
    cout << "enter size of aarray " << endl;
    cin >> size;
    pArray = (int *)malloc(size * sizeof(int));

    if (pArray == nullptr)
    {
        return 0;
    }

    for (int indx = 0; indx < size; indx++)
    {
        pArray[indx] = rand() % 500;
    }
    int max, min;

    getMaxMin(pArray, max, min, size);
    free(pArray);
    cout << "max: " << max << " Min " << min << endl;
}

void getMaxMin(const int *pArray, int &max, int &min, int size)
{

    const int *pStore = pArray;
    int arrSz = size;
    max = min - *pArray;

    while (size)
    {
        if (*pArray < min)
        {
            min = *pArray;
        }
        pArray++;
        size--;
    }

    size = arrSz;
    pArray = pStore;

    while (size)
    {

        if (*pArray > max)
        {
            max = *pArray;
        }
        pArray++;
        size--;
    }
}

