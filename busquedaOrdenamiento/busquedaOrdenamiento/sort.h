#ifndef SORT_H
#define SORT_H

/**
 * @file sort.h
 * @brief Algoritmos de ordenamiento.
 */

void ordenarBurbuja(int arr[], int n);
void ordenarSeleccion(int arr[], int n);
void ordenarInsercion(int arr[], int n);

void quickSort(int arr[], int low, int high,
    int& comps, int& swaps);

void mergeSort(int arr[], int l, int r,
    int& comps);

#endif