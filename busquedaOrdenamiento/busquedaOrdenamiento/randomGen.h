#pragma once
#ifndef RANDOMGEN_H
#define RANDOMGEN_H

/**
 * @file randomGen.h
 * @brief Declaraciones de funciones para generación de números aleatorios.
 * @author
 * @date 2026
 */

 /**
  * @brief Genera números aleatorios permitiendo repetición.
  *
  * Llena el arreglo con valores aleatorios entre 0 y n*10.
  *
  * @param arreglo Arreglo destino
  * @param n Tamaño final generado (por referencia)
  * @param tam Cantidad de elementos a generar
  */
void generarAleatoriosConRepeticion(int arreglo[], int& n, int tam);

/**
 * @brief Genera números aleatorios sin repetición.
 *
 * Utiliza un arreglo auxiliar para evitar duplicados.
 *
 * @param arreglo Arreglo destino
 * @param n Tamaño final generado
 * @param tam Cantidad de elementos a generar
 * @param M Valor máximo permitido (opcional)
 */
void generarAleatoriosSinRepeticion(int arreglo[], int& n, int tam, int M = 0);

#endif