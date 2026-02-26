#ifndef SEARCH_H
#define SEARCH_H

/**
 * @file search.h
 * @brief Algoritmos de búsqueda.
 */

 /**
  * @brief Búsqueda secuencial.
  * @param arr Arreglo
  * @param n Tamaño
  * @param valor Valor buscado
  * @return índice o -1
  */
int busquedaSecuencial(int arr[], int n, int valor);

/**
 * @brief Búsqueda binaria (requiere arreglo ordenado).
 * @param arr Arreglo
 * @param n Tamaño
 * @param valor Valor buscado
 * @return índice o -1
 */
int busquedaBinaria(int arr[], int n, int valor);

#endif