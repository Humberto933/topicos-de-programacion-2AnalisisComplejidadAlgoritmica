#pragma once
#ifndef VIEW_H
#define VIEW_H

/**
 * @file view.h
 * @brief Declaración de funciones de interfaz de usuario.
 *
 * Este módulo contiene funciones para mostrar menús,
 * imprimir arreglos y solicitar datos al usuario.
 */

 /**
  * @brief Muestra el menú principal.
  */
void mostrarMenu();

/**
 * @brief Imprime los elementos del arreglo.
 * @param arreglo Arreglo a mostrar
 * @param n Tamaño
 */
void mostrarArreglo(int arreglo[], int n);

/**
 * @brief Solicita un valor al usuario.
 * @return Valor ingresado
 */
int pedirValor();

/**
 * @brief Muestra menú de métodos de ordenamiento.
 * @return opción seleccionada
 */
int mostrarMenuOrdenamiento();

#endif