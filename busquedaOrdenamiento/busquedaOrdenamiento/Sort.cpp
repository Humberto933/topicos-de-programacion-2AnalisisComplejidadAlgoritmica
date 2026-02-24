#include "sort.h"
#include <iostream>
using namespace std;

void ordenarBurbuja(int arreglo[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << "Comparando " << arreglo[j] << " y " << arreglo[j + 1] << endl;
            if (arreglo[j] > arreglo[j + 1])
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
                cout << "Intercambiando: " << arreglo[j] << " con " << arreglo[j + 1] << endl;
            }
        }
    }
}

void ordenarSeleccion(int arreglo[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            cout << "Comparando " << arreglo[j] << " y " << arreglo[min] << endl;
            if (arreglo[j] < arreglo[min])
            {
                min = j;
            }
        }
        temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
        cout << "Poniendo " << arreglo[i] << " en la posición " << i << endl;
    }
}

void ordenarInsercion(int arreglo[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int clave = arreglo[i];
        int j = i - 1;
        cout << "Insertando " << clave << endl;
        while (j >= 0 && arreglo[j] > clave)
        {
            cout << "Moviendo " << arreglo[j] << " a la posición " << j + 1 << endl;
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
        cout << "Colocando " << clave << " en la posición " << j + 1 << endl;
    }
}

void quickSort(int arreglo[], int izquierda, int derecha, int& comparaciones, int& intercambios)
{
    int i = izquierda, j = derecha;
    int pivote = arreglo[(izquierda + derecha) / 2];
    cout << "QuickSort pivot: " << pivote << " de posición " << (izquierda + derecha) / 2 << endl;

    int temp;
    while (i <= j)
    {
        while (arreglo[i] < pivote) { i++; comparaciones++; }
        while (arreglo[j] > pivote) { j--; comparaciones++; }
        if (i <= j)
        {
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
            intercambios++;
            cout << "Intercambiando " << arreglo[i] << " y " << arreglo[j] << endl;
            i++; j--;
        }
    }
    if (izquierda < j) quickSort(arreglo, izquierda, j, comparaciones, intercambios);
    if (i < derecha) quickSort(arreglo, i, derecha, comparaciones, intercambios);
}

void merge(int arreglo[], int izquierda, int medio, int derecha, int& comparaciones)
{
    int i = izquierda, j = medio + 1, k = 0;
    int temp[100];

    while (i <= medio && j <= derecha)
    {
        comparaciones++;
        if (arreglo[i] <= arreglo[j])
        {
            temp[k++] = arreglo[i++];
        }
        else
        {
            temp[k++] = arreglo[j++];
        }
    }
    while (i <= medio) temp[k++] = arreglo[i++];
    while (j <= derecha) temp[k++] = arreglo[j++];

    for (i = izquierda, k = 0; i <= derecha; i++, k++)
        arreglo[i] = temp[k];
}

void mergeSort(int arreglo[], int izquierda, int derecha, int& comparaciones)
{
    if (izquierda < derecha)
    {
        int medio = (izquierda + derecha) / 2;
        mergeSort(arreglo, izquierda, medio, comparaciones);
        mergeSort(arreglo, medio + 1, derecha, comparaciones);
        merge(arreglo, izquierda, medio, derecha, comparaciones);
    }
}