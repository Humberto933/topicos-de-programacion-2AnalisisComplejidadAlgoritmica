#include "Arreglo.h"
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
using namespace std;

Arreglo::Arreglo() {
    n = 10;
    int inicial[10] = { 33, 5, 90, 12, 41, 8, 77, 20, 50, 62 };
    for (int i = 0; i < n; i++)
        arreglo[i] = inicial[i];
    srand(static_cast<unsigned int>(time(0))); // semilla aleatoria
}

// ==================== VISUALIZACION ====================
void Arreglo::mostrarMenu() {
    cout << "\n=== MENU ===\n";
    cout << "1. Busqueda Secuencial\n";
    cout << "2. Busqueda Binaria (ordena automaticamente)\n";
    cout << "3. Ordenar Arreglo\n";
    cout << "4. Generar aleatorios con repeticion\n";
    cout << "5. Generar aleatorios sin repeticion\n";
    cout << "6. Salir\n";
    cout << "Seleccione opcion: ";
}

void Arreglo::mostrarArreglo() {
    cout << "\nArreglo: ";
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

int Arreglo::pedirValor() {
    int valor;
    cout << "Ingrese valor: ";
    cin >> valor;
    return valor;
}

int Arreglo::mostrarMenuOrdenamiento() {
    int opcion;
    cout << "\n=== METODOS DE ORDENAMIENTO ===\n";
    cout << "1. Burbuja\n2. Seleccion\n3. Insercion\n4. QuickSort\n5. MergeSort\n";
    cout << "Seleccione metodo: ";
    cin >> opcion;
    return opcion;
}

int Arreglo::getN() { return n; }

// ==================== BUSQUEDAS ====================
int Arreglo::busquedaSecuencial(int valor) {
    for (int i = 0; i < n; i++)
        if (arreglo[i] == valor) return i;
    return -1;
}

int Arreglo::busquedaBinaria(int valor) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int medio = (izq + der) / 2;
        if (arreglo[medio] == valor) return medio;
        else if (arreglo[medio] < valor) izq = medio + 1;
        else der = medio - 1;
    }
    return -1;
}

// ==================== ORDENAMIENTOS ====================
void Arreglo::ordenarBurbuja() {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arreglo[j] > arreglo[j + 1])
                swap(arreglo[j], arreglo[j + 1]);
}

void Arreglo::ordenarSeleccion() {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arreglo[j] < arreglo[min]) min = j;
        swap(arreglo[i], arreglo[min]);
    }
}

void Arreglo::ordenarInsercion() {
    for (int i = 1; i < n; i++) {
        int clave = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > clave) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
    }
}

void Arreglo::quickSort(int izquierda, int derecha, int& comparaciones, int& intercambios) {
    int i = izquierda, j = derecha;
    int pivote = arreglo[(izquierda + derecha) / 2];
    while (i <= j) {
        while (arreglo[i] < pivote) { i++; comparaciones++; }
        while (arreglo[j] > pivote) { j--; comparaciones++; }
        if (i <= j) { swap(arreglo[i], arreglo[j]); intercambios++; i++; j--; }
    }
    if (izquierda < j) quickSort(izquierda, j, comparaciones, intercambios);
    if (i < derecha) quickSort(i, derecha, comparaciones, intercambios);
}

void Arreglo::merge(int izquierda, int medio, int derecha, int& comparaciones) {
    int temp[10000]; // suficiente para MAX
    int i = izquierda, j = medio + 1, k = 0;
    while (i <= medio && j <= derecha) {
        comparaciones++;
        if (arreglo[i] <= arreglo[j]) temp[k++] = arreglo[i++];
        else temp[k++] = arreglo[j++];
    }
    while (i <= medio) temp[k++] = arreglo[i++];
    while (j <= derecha) temp[k++] = arreglo[j++];
    for (i = izquierda, k = 0; i <= derecha; i++, k++) arreglo[i] = temp[k];
}

void Arreglo::mergeSort(int izquierda, int derecha, int& comparaciones) {
    if (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;
        mergeSort(izquierda, medio, comparaciones);
        mergeSort(medio + 1, derecha, comparaciones);
        merge(izquierda, medio, derecha, comparaciones);
    }
}

// ==================== GENERACION ALEATORIA ====================
void Arreglo::generarAleatoriosConRepeticion(int tamaño, int maxValor) {
    if (tamaño > MAX) tamaño = MAX;
    n = tamaño;
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % maxValor + 1;
        cout << "Pos " << i << " = " << arreglo[i] << endl;
    }
}

void Arreglo::generarAleatoriosSinRepeticion(int tamaño, int maxValor) {
    if (tamaño > MAX) tamaño = MAX;
    n = tamaño;
    for (int i = 0; i < n; i++) {
        int num;
        bool repetido;
        do {
            num = rand() % maxValor + 1;
            repetido = false;
            for (int j = 0; j < i; j++)
                if (arreglo[j] == num) { repetido = true; break; }
        } while (repetido);
        arreglo[i] = num;
        cout << "Pos " << i << " = " << arreglo[i] << endl;
    }
}