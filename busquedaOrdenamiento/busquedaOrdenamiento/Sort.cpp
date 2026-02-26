#include "sort.h"

static void swap(int& a, int& b) { int t = a; a = b; b = t; }

void ordenarBurbuja(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void ordenarSeleccion(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(arr[i], arr[min]);
    }
}

void ordenarInsercion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static int partition(int arr[], int low, int high,
    int& comps, int& swaps)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comps++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSort(int arr[], int low, int high,
    int& comps, int& swaps)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, comps, swaps);
        quickSort(arr, low, pi - 1, comps, swaps);
        quickSort(arr, pi + 1, high, comps, swaps);
    }
}

static void merge(int arr[], int l, int m, int r, int& comps)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        comps++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r, int& comps)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, comps);
        mergeSort(arr, m + 1, r, comps);
        merge(arr, l, m, r, comps);
    }
}