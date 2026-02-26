#include "randomGen.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generarAleatoriosConRepeticion(int arreglo[], int& n, int tam)
{
    n = tam;
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arreglo[i] = rand() % (n * 10);

    cout << "\nDatos generados:\n";
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << "\n";
}

void generarAleatoriosSinRepeticion(int arreglo[], int& n, int tam, int M)
{
    n = tam;
    srand(time(NULL));

    int max_val = (M > 0) ? M : n * 10;
    int* aux = new int[max_val];

    for (int i = 0; i < max_val; i++)
        aux[i] = i;

    for (int i = 0; i < n; i++)
    {
        int idx = rand() % (max_val - i);
        arreglo[i] = aux[idx];
        aux[idx] = aux[max_val - i - 1];
    }

    delete[] aux;

    cout << "\nDatos generados:\n";
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << "\n";
}