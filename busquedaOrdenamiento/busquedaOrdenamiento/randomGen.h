#ifndef RANDOMGEN_H
#define RANDOMGEN_H

/**
 * @file randomGen.h
 * @brief Generación de arreglos aleatorios.
 */

 /**
  * @brief Genera números aleatorios con repetición.
  * @param arreglo Arreglo destino
  * @param n Cantidad generada
  * @param tam Tamaño solicitado
  */
void generarAleatoriosConRepeticion(int arreglo[], int& n, int tam);

/**
 * @brief Genera números aleatorios sin repetición.
 * @param arreglo Arreglo destino
 * @param n Cantidad generada
 * @param tam Tamaño solicitado
 * @param M Valor máximo posible (opcional)
 */
void generarAleatoriosSinRepeticion(int arreglo[], int& n, int tam, int M = 0);

#endif