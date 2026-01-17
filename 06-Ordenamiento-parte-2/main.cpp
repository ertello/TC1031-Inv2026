/*
 * Algoritmos de ordenamiento parte 01
 *
 * Compilación con debug:
 *  g++ -std=c++17 *.cpp -Wall -g -o main
 *
 * Compilación para ejecucion:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redireccion (input and output):
 *  ./main < TestCases/t1.txt
 *  ./main < TestCases/t2.txt > salida.txt
 */

#include <chrono>
#include <iostream>
#include "AlgorithmSort.h"

using std::cin;
using std::cout;
using std::endl;

int main(void) {
  int flag;
  size_t i, size, comparaciones, swaps;
  cin >> size;
  cout << "Size: " << size << endl;
  cin >> flag;
  cout << "Print flag: " << flag << endl;
  std::vector<int> myVector(size);
  // Lectura de los elementos del vector
  for (i = 0; i < size; i++) {
    cin >> myVector[i];
  }
  if (flag) {
    cout << "Los elementos del vector son: " << endl;
    for (i = 0; i < size; i++) {
      cout << myVector[i] << " ";
    }
    cout << endl;
  }
  // Instancia un objeto de la clase AlgoritmoSort
  AlgorithmSort<int> sortObj;

  // Ordenamiento del vector utilizando swap sort
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();
  //cout << "Swap sort" << endl;
  comparaciones = swaps = 0;
/*  
  sortObj.swapSort(myVector, size, comparaciones, swaps);
  if (flag)
    sortObj.printVector(myVector);
  // Termina conteo de tiempo de ejecución
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  cout << "\tComparaciones: " << comparaciones << endl;
  cout << "\tIntercambios: " << swaps << endl;
  cout << "\tTiempo de ejecución en ms: " << totalTime / std::chrono::milliseconds(1) << endl;
  // Mezcla los elementos del vector en forma aleatoria
  sortObj.randomShuffle(myVector);
*/  
  // Ordenamiento del vector utilizando selection sort
  // Inicio conteo de tiempo de ejecución
  startTime = std::chrono::high_resolution_clock::now();
  cout << "Selection sort" << endl;
  comparaciones = swaps = 0;
  sortObj.selectionSort(myVector, size, comparaciones, swaps);
  if (flag)
    sortObj.printVector(myVector);
  // Termina conteo de tiempo de ejecución
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  cout << "\tComparaciones: " << comparaciones << endl;
  cout << "\tIntercambios: " << swaps << endl;
  cout << "\tTiempo de ejecución en ms: " << totalTime / std::chrono::milliseconds(1) << endl;
  
  // Mezcla los elementos del vector en forma aleatoria
  sortObj.randomShuffle(myVector);
/*
  // Ordenamiento del vector utilizando bubble sort
  // Inicio conteo de tiempo de ejecución
  startTime = std::chrono::high_resolution_clock::now();
  cout << "Bubble sort" << endl;
  comparaciones = swaps = 0;
  sortObj.bubbleSort(myVector, size, comparaciones, swaps);
  if (flag)
    sortObj.printVector(myVector);
  // Termina conteo de tiempo de ejecución
  endTime = std::chrono::high_resolution_clock::now();
  totalTime = endTime - startTime;
  cout << "\tComparaciones: " << comparaciones << endl;
  cout << "\tIntercambios: " << swaps << endl;
  cout << "\tTiempo de ejecución en ms: " << totalTime / std::chrono::milliseconds(1) << endl;

  // Mezcla los elementos del vector en forma aleatoria
  sortObj.randomShuffle(myVector);

  // Ordenamiento del vector utilizando insertion sort
  // Inicio conteo de tiempo de ejecución
  startTime = std::chrono::high_resolution_clock::now();
  cout << "Insertion sort" << endl;
  comparaciones = swaps = 0;
  sortObj.insertionSort(myVector, size, comparaciones, swaps);
  if (flag)
    sortObj.printVector(myVector);
  // Termina conteo de tiempo de ejecución
  endTime = std::chrono::high_resolution_clock::now();
  totalTime = endTime - startTime;
  cout << "\tComparaciones: " << comparaciones << endl;
  cout << "\tIntercambios: " << swaps << endl;
  cout << "\tTiempo de ejecución en ms: " << totalTime / std::chrono::milliseconds(1) << endl;

  // Mezcla los elementos del vector en forma aleatoria
  sortObj.randomShuffle(myVector);
*/
  // Ordenamiento del vector utilizando merge sort
  // Inicio conteo de tiempo de ejecución
  startTime = std::chrono::high_resolution_clock::now();
  cout << "Merge sort" << endl;
  comparaciones = swaps = 0;
  sortObj.mergeSort(myVector, 0, size-1, comparaciones);
  if (flag)
    sortObj.printVector(myVector);
  // Termina conteo de tiempo de ejecución
  endTime = std::chrono::high_resolution_clock::now();
  totalTime = endTime - startTime;
  cout << "\tComparaciones: " << comparaciones << endl;
  cout << "\tTiempo de ejecución en ms: " << totalTime / std::chrono::milliseconds(1) << endl;

  // Mezcla los elementos del vector en forma aleatoria
  sortObj.randomShuffle(myVector);

  // Ordenamiento del vector utilizando quicksort
  // Inicio conteo de tiempo de ejecución
  startTime = std::chrono::high_resolution_clock::now();
  cout << "Quicksort" << endl;
  comparaciones = swaps = 0;
  sortObj.quickSort(myVector, 0, size-1, comparaciones, swaps);
  if (flag)
    sortObj.printVector(myVector);
  // Termina conteo de tiempo de ejecución
  endTime = std::chrono::high_resolution_clock::now();
  totalTime = endTime - startTime;
  cout << "\tComparaciones: " << comparaciones << endl;
  cout << "\tIntercambios: " << swaps << endl;
  cout << "\tTiempo de ejecución en ms: " << totalTime / std::chrono::milliseconds(1) << endl;
  
  return 0;
}