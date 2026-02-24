#pragma once
#ifndef SEARCH_H
#define SEARCH_H

/**
 * @file search.h
 * @brief Declaración de algoritmos de búsqueda.
 */

 /**
  * @brief Realiza búsqueda secuencial.
  *
  * Recorre el arreglo elemento por elemento.
  *
  * @param arreglo Arreglo de datos
  * @param n Tamaño
  * @param valor Valor a buscar
  * @return índice encontrado o -1
  */
int busquedaSecuencial(int arreglo[], int n, int valor);

/**
 * @brief Realiza búsqueda binaria.
 *
 * Requiere que el arreglo esté ordenado previamente.
 *
 * @param arreglo Arreglo ordenado
 * @param n Tamaño
 * @param valor Valor buscado
 * @return índice encontrado o -1
 */
int busquedaBinaria(int arreglo[], int n, int valor);

#endif