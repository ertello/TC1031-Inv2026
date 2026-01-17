/*
 * Algoritmos de busqueda
 *
 * Compilación con debug:
 *  g++ -std=c++17 *.cpp -Wall -g -o main
 *
 * Compilación para ejecucion:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redireccion (input and output):
 *  ./main < TestCases/test01.txt
 *  ./main < TestCases/test03.txt > salida.txt
 *
 * Casos 1 a 3 tiene vectores no ordenados
 * Casos 4 a 6 tiene vectores ordenados
 */

#include <chrono>
#include <iostream>
#include <vector>
#include "SearchAlgorithm.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int i, tmp, size, key, flag;
  cin >> size;
  cout << "Size: " << size << endl;
  cin >> key;
  cout << "Key: " << key << endl;
  cin >> flag;
  cout << "Print flag: " << flag << endl;
  // Declaración del
  std::vector<int> myVector;
  // Lectura de los elementos del arreglo
  for(i = 0; i < size; i++) {
     cin >> tmp;
     myVector.push_back(tmp);
  }
  if (flag) {
    cout << "Los elementos del arreglo son: " << endl;
    for(i = 0; i < size; i++) {
      cout << myVector[i] << " ";
    }
    cout << endl;
  }
  // Instancia un objeto de la clase AlgorithmSearch
  SearchAlgorithm<int> searchObj;
  size_t comparaciones = 0;
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();
  cout << "Key buscado esta en indice: " << searchObj.busquedaSecuencial(myVector, key, comparaciones) << endl;
  //cout << "Key buscado esta en indice: " << searchObj.busquedaSecuencialVectorOrdenado(myVector, key, comparaciones) << endl;
  //cout << "Key buscado esta en indice: " << searchObj.busquedaBinaria(myVector, key, comparaciones) << endl;
  //cout << "Key buscado esta en indice: " <<    searchObj.busquedaBinariaRecursiva(myVector, 0, myVector.size()-1, key, comparaciones) << endl;

  // Termina conteo de tiempo de ejecución
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;

  cout << "Tiempo de ejecución en ms: " <<
totalTime/std::chrono::milliseconds(1) << endl; cout << "Numero de comparaciones: " << comparaciones << endl; 
  return 0;
}
