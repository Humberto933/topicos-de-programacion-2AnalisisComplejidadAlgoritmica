/**
 * @file randomGen.cpp
 * @brief Implementación de generadores de números aleatorios.
 */

#include "randomGen.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief Genera números aleatorios con repetición.
 */
void generarAleatoriosConRepeticion(int arreglo[], int& n, int tam)
{
    n = tam;
    srand(time(NULL));

    cout << "\nGenerando numeros aleatorios CON repeticion:\n";

    for (int i = 0; i < n; i++)
    {
        arreglo[i] = rand() % (n * 10);
        cout << "arreglo[" << i << "] = " << arreglo[i] << endl;
    }
}

/**
 * @brief Genera números aleatorios sin repetición.
 */
void generarAleatoriosSinRepeticion(int arreglo[], int& n, int tam, int M)
{
    n = tam;
    srand(time(NULL));

    int max_val = (M > 0) ? M : n * 10;

    int* aux = new int[max_val];

    for (int i = 0; i < max_val; i++)
        aux[i] = i;

    cout << "\nGenerando numeros aleatorios SIN repeticion:\n";

    for (int i = 0; i < n; i++)
    {
        int idx = rand() % (max_val - i);

        arreglo[i] = aux[idx];

        cout << "arreglo[" << i << "] = " << arreglo[i] << endl;

        aux[idx] = aux[max_val - i - 1];
    }

    delete[] aux;
}