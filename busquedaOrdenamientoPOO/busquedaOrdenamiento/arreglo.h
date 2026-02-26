/**
 * @file Arreglo.h
 * @brief Class that encapsulates array operations.
 */

#ifndef ARREGLO_H
#define ARREGLO_H

 /**
  * @class Arreglo
  * @brief Encapsulates searching, sorting and generation algorithms.
  */
class Arreglo
{
private:

    static const int MAX = 100000;
    int arreglo[MAX];
    int n;

    void merge(int izq, int mid, int der);

public:

    Arreglo();

    int getN() const;

    void imprimir() const;

    int pedirValor();

    int busquedaSecuencial(int valor);
    int busquedaBinaria(int valor);

    void ordenarBurbuja();
    void ordenarSeleccion();
    void ordenarInsercion();
    void quickSort(int izq, int der);
    void mergeSort(int izq, int der);

    void generarAleatoriosConRepeticion(int tam, int maxValor);
    void generarAleatoriosSinRepeticion(int tam, int maxValor);
};

#endif