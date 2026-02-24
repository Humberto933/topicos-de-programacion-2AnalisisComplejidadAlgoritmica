#include <iostream>
using namespace std;
#include "view.h"

// Menú principal con nuevas opciones de generación de números
void mostrarMenu()
{
    cout << "\n=== MENU ===\n";
    cout << "1. Busqueda Secuencial\n";
    cout << "2. Busqueda Binaria (ordena automaticamente)\n";
    cout << "3. Ordenar Arreglo\n";
    cout << "4. Generar numeros aleatorios CON repeticion\n";
    cout << "5. Generar numeros aleatorios SIN repeticion\n";
    cout << "6. Salir\n";
    cout << "Seleccione opcion: ";
}

// Muestra el arreglo en pantalla
void mostrarArreglo(int arreglo[], int n)
{
    cout << "\nArreglo: ";
    for (int i = 0; i < n; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Solicita al usuario un valor para buscar
int pedirValor()
{
    int valor;
    cout << "Ingrese valor a buscar: ";
    cin >> valor;
    return valor;
}

// Menú de métodos de ordenamiento
int mostrarMenuOrdenamiento()
{
    int opcion;
    cout << "\n=== METODOS DE ORDENAMIENTO ===\n";
    cout << "1. Burbuja\n";
    cout << "2. Seleccion\n";
    cout << "3. Insercion\n";
    cout << "4. QuickSort\n";
    cout << "5. MergeSort\n";
    cout << "Seleccione metodo: ";
    cin >> opcion;
    return opcion;
}