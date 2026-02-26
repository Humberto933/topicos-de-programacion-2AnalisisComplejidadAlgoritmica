/**
 * @file Menu.cpp
 * @brief Implements program menu.
 */

#include "Menu.h"
#include "Arreglo.h"
#include "Timer.h"
#include <iostream>

using namespace std;

static void mostrarMenu()
{
    cout << "\n1 Sequential search\n";
    cout << "2 Binary search\n";
    cout << "3 Sort\n";
    cout << "4 Generate random with repetition\n";
    cout << "5 Generate random without repetition\n";
    cout << "6 Exit\n";
    cout << "Option: ";
}

static int menuOrdenamientos()
{
    int op;
    cout << "\n1 Bubble\n2 Selection\n3 Insertion\n4 QuickSort\n5 MergeSort\nMethod: ";
    cin >> op;
    return op;
}

void ejecutarMenu()
{
    Arreglo A;
    int op;

    do
    {
        mostrarMenu();
        cin >> op;

        if (op == 1)
        {
            int v = A.pedirValor();
            int pos;

            double t = medirTiempo([&]() { pos = A.busquedaSecuencial(v); });

            cout << "Result " << pos << endl;
            cout << "Time " << t << " us\n";
        }

        else if (op == 2)
        {
            A.quickSort(0, A.getN() - 1);

            cout << "Sorted array:\n";
            A.imprimir();

            int v = A.pedirValor();
            int pos;

            double t = medirTiempo([&]() { pos = A.busquedaBinaria(v); });

            cout << "Result " << pos << endl;
            cout << "Time " << t << " us\n";
        }

        else if (op == 3)
        {
            int m = menuOrdenamientos();
            double t = 0;

            if (m == 1) t = medirTiempo([&]() {A.ordenarBurbuja(); });
            else if (m == 2) t = medirTiempo([&]() {A.ordenarSeleccion(); });
            else if (m == 3) t = medirTiempo([&]() {A.ordenarInsercion(); });
            else if (m == 4) t = medirTiempo([&]() {A.quickSort(0, A.getN() - 1); });
            else if (m == 5) t = medirTiempo([&]() {A.mergeSort(0, A.getN() - 1); });
            else continue;

            cout << "Time " << t << " us\n";
            cout << "Result:\n";
            A.imprimir();
        }

        else if (op == 4)
        {
            int t, max;
            cout << "Size: ";
            cin >> t;
            cout << "Max value: ";
            cin >> max;

            double time = medirTiempo([&]() {
                A.generarAleatoriosConRepeticion(t, max);
                });

            cout << "Generated:\n";
            A.imprimir();
            cout << "Time " << time << " us\n";
        }

        else if (op == 5)
        {
            int t, max;
            cout << "Size: ";
            cin >> t;
            cout << "Max value: ";
            cin >> max;

            double time = medirTiempo([&]() {
                A.generarAleatoriosSinRepeticion(t, max);
                });

            cout << "Generated:\n";
            A.imprimir();
            cout << "Time " << time << " us\n";
        }

    } while (op != 6);
}