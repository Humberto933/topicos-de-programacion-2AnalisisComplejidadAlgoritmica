/**
 * @file Timer.h
 * @brief Utility for measuring execution time.
 */

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

 /**
  * @brief Measures execution time of a function in microseconds.
  *
  * @tparam F Callable type
  * @param f Function to execute
  * @return Execution time in microseconds
  */
template<typename F>
double medirTiempo(F f)
{
    auto inicio = std::chrono::high_resolution_clock::now();
    f();
    auto fin = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::micro>(fin - inicio).count();
}

#endif