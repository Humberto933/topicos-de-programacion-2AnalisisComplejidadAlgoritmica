#pragma once
#ifndef ARREGLO_H
#define ARREGLO_H

/**
 * @file Arreglo.h
 * @brief Definición de la clase Arreglo.
 *
 * Esta clase encapsula un arreglo de enteros y provee métodos
 * para búsqueda, ordenamiento, generación de números aleatorios
 * y visualización en consola.
 */
class Arreglo {
private:
    /**
     * @brief Tamaño máximo permitido del arreglo.
     */
    static const int MAX = 10000;

    /**
     * @brief Contenedor interno de datos.
     */
    int arreglo[MAX];

    /**
     * @brief Cantidad actual de elementos.
     */
    int n;

public:

    /**
     * @brief Constructor.
     *
     * Inicializa el arreglo con valores predefinidos
     * y establece la semilla aleatoria.
     */
    Arreglo();

    // ================= VISUALIZACION =================

    /**
     * @brief Muestra el menú principal.
     */
    void mostrarMenu();

    /**
     * @brief Imprime el arreglo actual.
     */
    void mostrarArreglo();

    /**
     * @brief Solicita un valor al usuario.
     * @return valor ingresado
     */
    int pedirValor();

    /**
     * @brief Muestra menú de métodos de ordenamiento.
     * @return opción seleccionada
     */
    int mostrarMenuOrdenamiento();

    /**
     * @brief Obtiene tamaño actual.
     * @return tamaño del arreglo
     */
    int getN();

    // ================= BUSQUEDAS =================

    /**
     * @brief Búsqueda secuencial.
     * @param valor valor a buscar
     * @return índice encontrado o -1
     */
    int busquedaSecuencial(int valor);

    /**
     * @brief Búsqueda binaria.
     * @param valor valor a buscar
     * @return índice o -1
     * @note Requiere arreglo ordenado.
     */
    int busquedaBinaria(int valor);

    // ================= ORDENAMIENTOS =================

    /**
     * @brief Ordenamiento burbuja.
     */
    void ordenarBurbuja();

    /**
     * @brief Ordenamiento selección.
     */
    void ordenarSeleccion();

    /**
     * @brief Ordenamiento inserción.
     */
    void ordenarInsercion();

    /**
     * @brief QuickSort recursivo.
     */
    void quickSort(int izquierda, int derecha, int& comparaciones, int& intercambios);

    /**
     * @brief MergeSort recursivo.
     */
    void mergeSort(int izquierda, int derecha, int& comparaciones);

    // ================= GENERACION =================

    /**
     * @brief Genera números aleatorios con repetición.
     */
    void generarAleatoriosConRepeticion(int tamaño, int maxValor);

    /**
     * @brief Genera números aleatorios sin repetición.
     */
    void generarAleatoriosSinRepeticion(int tamaño, int maxValor);

private:

    /**
     * @brief Función auxiliar de MergeSort.
     */
    void merge(int izquierda, int medio, int derecha, int& comparaciones);
};

#endif