#pragma once
#ifndef SORT_H
#define SORT_H

/**
 * @file sort.h
 * @brief Declaración de algoritmos de ordenamiento.
 *
 * Contiene funciones clásicas de ordenamiento utilizadas
 * para comparar rendimiento y comportamiento.
 */

 /**
  * @brief Ordena usando el algoritmo Burbuja.
  * @param arreglo Arreglo a ordenar
  * @param n Tamaño del arreglo
  */
void ordenarBurbuja(int arreglo[], int n);

/**
 * @brief Ordena usando Selección.
 * @param arreglo Arreglo a ordenar
 * @param n Tamaño
 */
void ordenarSeleccion(int arreglo[], int n);

/**
 * @brief Ordena usando Inserción.
 * @param arreglo Arreglo a ordenar
 * @param n Tamaño
 */
void ordenarInsercion(int arreglo[], int n);

/**
 * @brief Ordena usando QuickSort.
 *
 * @param arreglo Arreglo
 * @param izquierda Índice inicial
 * @param derecha Índice final
 * @param comparaciones Contador de comparaciones
 * @param intercambios Contador de swaps
 */
void quickSort(int arreglo[], int izquierda, int derecha, int& comparaciones, int& intercambios);

/**
 * @brief Ordena usando MergeSort.
 * @param arreglo Arreglo
 * @param izquierda Inicio
 * @param derecha Fin
 * @param comparaciones Contador de comparaciones
 */
void mergeSort(int arreglo[], int izquierda, int derecha, int& comparaciones);

#endif