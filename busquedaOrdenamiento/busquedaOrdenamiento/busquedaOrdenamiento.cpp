#include <iostream>
#include <chrono>

#include "view.h"
#include "sort.h"
#include "search.h"
#include "randomGen.h"

using namespace std;
using namespace chrono;

template<typename Func>
double medirTiempo(Func f)
{
    auto i = high_resolution_clock::now();
    f();
    auto f2 = high_resolution_clock::now();
    return duration_cast<microseconds>(f2 - i).count() / 1000.0;
}

int main()
{
    int arr[20000];
    int n = 10;

    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            mostrarArreglo(arr, n);
            int v = pedirValor();
            int pos;

            double t = medirTiempo([&]() {
                pos = busquedaSecuencial(arr, n, v);
                });

            cout << "Pos=" << pos << " Tiempo=" << t << " ms\n";
            break;
        }

        case 2:
        {
            int v = pedirValor();
            int pos;

            double t = medirTiempo([&]() {
                pos = busquedaBinaria(arr, n, v);
                });

            cout << "Pos=" << pos << " Tiempo=" << t << " ms\n";
            break;
        }

        case 3:
        {
            int m = mostrarMenuOrdenamiento();
            int comps = 0, swaps = 0;
            double t = 0;

            if (m == 1) t = medirTiempo([&]() {ordenarBurbuja(arr, n); });
            if (m == 2) t = medirTiempo([&]() {ordenarSeleccion(arr, n); });
            if (m == 3) t = medirTiempo([&]() {ordenarInsercion(arr, n); });
            if (m == 4) t = medirTiempo([&]() {quickSort(arr, 0, n - 1, comps, swaps); });
            if (m == 5) t = medirTiempo([&]() {mergeSort(arr, 0, n - 1, comps); });

            mostrarArreglo(arr, n);
            cout << "Tiempo=" << t << " ms\n";
            break;
        }

        case 4:
        {
            cout << "Ingrese tamaño del arreglo: ";
            cin >> n;
            generarAleatoriosConRepeticion(arr, n, n);
            break;
        }

        case 5:
        {
            cout << "Ingrese tamaño del arreglo: ";
            cin >> n;
            generarAleatoriosSinRepeticion(arr, n, n);
            break;
        }

        case 6:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 6);

    return 0;
}