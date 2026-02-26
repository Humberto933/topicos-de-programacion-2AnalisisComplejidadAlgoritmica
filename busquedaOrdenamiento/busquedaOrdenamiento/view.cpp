#include "view.h"
#include <iostream>
using namespace std;

void mostrarMenu()
{
    cout << "\n--- MENU ---\n";
    cout << "1. Busqueda Secuencial\n";
    cout << "2. Busqueda Binaria\n";
    cout << "3. Ordenar\n";
    cout << "4. Generar Aleatorios (con rep)\n";
    cout << "5. Generar Aleatorios (sin rep)\n";
    cout << "6. Salir\n";
}

int mostrarMenuOrdenamiento()
{
    int op;
    cout << "\n1.Burbuja\n2.Seleccion\n3.Insercion\n4.QuickSort\n5.MergeSort\n";
    cin >> op;
    return op;
}

void mostrarArreglo(int arr[], int n)
{
    cout << "\nArreglo:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int pedirValor()
{
    int v;
    cout << "Valor: ";
    cin >> v;
    return v;
}