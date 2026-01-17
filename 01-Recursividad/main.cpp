/**
 * Ejemplo que implementa el factorial recursivo para un numero n
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall -g -o main *.cpp
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/
#include <iostream>

size_t factorialRecursivo(size_t n) {
  if (n == 0) // caso base
    return 1;
  else // caso general
    return factorialRecursivo(n-1) * n;
}

size_t factorialIterativo(size_t n) {
  size_t f = 1;
  while (n != 0) {
    f = f * n;
    n = n - 1;
  }
  return f;
}

int main() {
  size_t value;
  std::cout << "Dame un numero positivo:" << std::endl;
  std::cin >> value;
  std::cout << "Su factorial es: " << factorialRecursivo(value) << std::endl;
  std::cout << "Su factorial iterativo es: " << factorialIterativo(value) << std::endl;
  return 0;
}