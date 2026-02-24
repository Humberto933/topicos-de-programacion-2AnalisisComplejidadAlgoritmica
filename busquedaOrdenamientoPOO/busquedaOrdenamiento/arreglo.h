#pragma once
#ifndef ARREGLO_H
#define ARREGLO_H

class Arreglo {
private:
    static const int MAX = 10000; // tamaño máximo
    int arreglo[MAX];              // arreglo interno
    int n;                         // tamaño actual

public:
    Arreglo();                     // constructor

    // Métodos de visualización
    void mostrarMenu();
    void mostrarArreglo();
    int pedirValor();
    int mostrarMenuOrdenamiento();

    // Obtener tamaño actual
    int getN();

    // Búsquedas
    int busquedaSecuencial(int valor);
    int busquedaBinaria(int valor);

    // Ordenamientos
    void ordenarBurbuja();
    void ordenarSeleccion();
    void ordenarInsercion();
    void quickSort(int izquierda, int derecha, int& comparaciones, int& intercambios);
    void mergeSort(int izquierda, int derecha, int& comparaciones);

    // Generación aleatoria
    void generarAleatoriosConRepeticion(int tamaño, int maxValor);
    void generarAleatoriosSinRepeticion(int tamaño, int maxValor);

private:
    void merge(int izquierda, int medio, int derecha, int& comparaciones);
};

#endif