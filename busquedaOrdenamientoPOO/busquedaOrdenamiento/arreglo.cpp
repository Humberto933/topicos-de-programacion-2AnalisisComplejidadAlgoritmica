/**
 * @file Arreglo.cpp
 * @brief Implementation of Arreglo class.
 */

#include "Arreglo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Arreglo::Arreglo()
{
    n = 10;
    int ini[10] = { 33,5,90,12,41,8,77,20,50,62 };

    for (int i = 0; i < n; i++)
        arreglo[i] = ini[i];

    srand((unsigned)time(0));
}

int Arreglo::getN() const
{
    return n;
}

void Arreglo::imprimir() const
{
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

int Arreglo::pedirValor()
{
    int v;
    cout << "Enter value: ";
    cin >> v;
    return v;
}

int Arreglo::busquedaSecuencial(int valor)
{
    for (int i = 0; i < n; i++)
        if (arreglo[i] == valor)
            return i;
    return -1;
}

int Arreglo::busquedaBinaria(int valor)
{
    int izq = 0;
    int der = n - 1;

    while (izq <= der)
    {
        int m = (izq + der) / 2;

        if (arreglo[m] == valor)
            return m;

        if (arreglo[m] < valor)
            izq = m + 1;
        else
            der = m - 1;
    }
    return -1;
}

void Arreglo::ordenarBurbuja()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arreglo[j] > arreglo[j + 1])
                swap(arreglo[j], arreglo[j + 1]);
}

void Arreglo::ordenarSeleccion()
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arreglo[j] < arreglo[min])
                min = j;

        swap(arreglo[i], arreglo[min]);
    }
}

void Arreglo::ordenarInsercion()
{
    for (int i = 1; i < n; i++)
    {
        int key = arreglo[i];
        int j = i - 1;

        while (j >= 0 && arreglo[j] > key)
        {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = key;
    }
}

void Arreglo::quickSort(int izq, int der)
{
    if (izq >= der) return;

    int pivote = arreglo[izq + rand() % (der - izq + 1)];
    int i = izq;
    int j = der;

    while (i <= j)
    {
        while (arreglo[i] < pivote) i++;
        while (arreglo[j] > pivote) j--;

        if (i <= j)
        {
            swap(arreglo[i], arreglo[j]);
            i++;
            j--;
        }
    }

    quickSort(izq, j);
    quickSort(i, der);
}

void Arreglo::merge(int izq, int mid, int der)
{
    static int temp[MAX];

    int i = izq;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= der)
        temp[k++] = (arreglo[i] < arreglo[j]) ? arreglo[i++] : arreglo[j++];

    while (i <= mid) temp[k++] = arreglo[i++];
    while (j <= der) temp[k++] = arreglo[j++];

    for (int t = 0; t < k; t++)
        arreglo[izq + t] = temp[t];
}

void Arreglo::mergeSort(int izq, int der)
{
    if (izq >= der) return;

    int m = (izq + der) / 2;

    mergeSort(izq, m);
    mergeSort(m + 1, der);
    merge(izq, m, der);
}

void Arreglo::generarAleatoriosConRepeticion(int tam, int maxValor)
{
    if (tam > MAX) tam = MAX;
    n = tam;

    for (int i = 0; i < n; i++)
        arreglo[i] = rand() % maxValor;
}

void Arreglo::generarAleatoriosSinRepeticion(int tam, int maxValor)
{
    if (tam > MAX) tam = MAX;
    if (maxValor < tam) maxValor = tam;

    n = tam;

    int* pool = new int[maxValor];

    for (int i = 0; i < maxValor; i++)
        pool[i] = i;

    for (int i = 0; i < n; i++)
    {
        int idx = rand() % (maxValor - i);
        arreglo[i] = pool[idx];
        pool[idx] = pool[maxValor - i - 1];
    }

    delete[] pool;
}