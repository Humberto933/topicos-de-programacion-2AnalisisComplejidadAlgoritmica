#include "search.h"

int busquedaSecuencial(int arr[], int n, int valor)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == valor)
            return i;
    return -1;
}

int busquedaBinaria(int arr[], int n, int valor)
{
    int izq = 0, der = n - 1;

    while (izq <= der)
    {
        int mid = (izq + der) / 2;

        if (arr[mid] == valor)
            return mid;

        if (arr[mid] < valor)
            izq = mid + 1;
        else
            der = mid - 1;
    }
    return -1;
}