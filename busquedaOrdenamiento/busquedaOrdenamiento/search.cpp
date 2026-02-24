/**
 * @file search.cpp
 * @brief Implementación de algoritmos de búsqueda.
 */

#include "search.h"

 /**
  * @brief Implementación de búsqueda secuencial.
  */
int busquedaSecuencial(int arreglo[], int n, int valor)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arreglo[i] == valor)
            return i;
    }

    return -1;
}

/**
 * @brief Implementación de búsqueda binaria.
 */
int busquedaBinaria(int arreglo[], int n, int valor)
{
    int izquierda = 0;
    int derecha = n - 1;
    int medio;

    while (izquierda <= derecha)
    {
        medio = (izquierda + derecha) / 2;

        if (arreglo[medio] == valor)
            return medio;
        else if (arreglo[medio] < valor)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1;
}