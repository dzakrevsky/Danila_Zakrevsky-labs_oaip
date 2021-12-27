#include<iostream>
using namespace std;


void qsort(int arr[], int fst, int last)
{
    int i, j, pivot, tmp;
    if (fst < last)
    {
        pivot = fst;
        i = fst;
        j = last;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        tmp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = tmp;
        qsort(arr, fst, j - 1);
        qsort(arr, j + 1, last);
    }
}

int main() {
    int a[] = { 10,9,8,7,6,100,5,4,3,1,2 };

    qsort(a, 0, 10);

    cout << "Sorted elements: ";
    for (int i = 0; i < 11; i++)
        cout << a[i] << endl;

    return 0;
}