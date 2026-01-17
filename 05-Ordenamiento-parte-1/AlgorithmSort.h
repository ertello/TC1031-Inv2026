#ifndef _ALGORITHM_SORT_H_
#define _ALGORITHM_SORT_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

template <class T>
class AlgorithmSort {
  private:
    // semilla del generador de numeros aleatorios (time-based)
    unsigned seed; 
    // generador de numeros aleatorios (Mersenne Twister 64 bits)
    std::mt19937_64 gen;

  public:
    AlgorithmSort();
    ~AlgorithmSort();
    void randomShuffle(std::vector<T> &A);
    void printVector(std::vector<T> A);
    
    void swapSort(std::vector<T> &A, size_t n, size_t &compara, size_t &swap);
    void selectionSort(std::vector<T> &A, size_t n, size_t &compara, size_t &swap);
    
};


template<class T>
AlgorithmSort<T>::AlgorithmSort() {
  // semilla del generador de numeros aleatorios (time-based)
  seed = std::chrono::system_clock::now().time_since_epoch().count();
  // generador de numeros aleatorios (Mersenne Twister 64 bits)
  std::mt19937_64 gen;
  // inicializar el generador con la semilla creada
  gen.seed(seed);
}

template<class T>
AlgorithmSort<T>::~AlgorithmSort() {

}

// Mezcla los elementos del vector en forma aleatoria
template<class T>
void AlgorithmSort<T>::randomShuffle(std::vector<T> &A) {
  std::shuffle(A.begin(), A.end(), gen);
}

// Imprime en pantalla los elementos del vector
template<class T>
void AlgorithmSort<T>::printVector(std::vector<T> A) {
    std::cout << "Los elementos del vector ordenado son: " << std::endl;
    for(size_t i = 0; i < A.size(); i++) {
      std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// O(n^2) peor caso
template<class T>
void AlgorithmSort<T>::swapSort(std::vector<T> &A, size_t n, size_t &compara, size_t &swap) {
  compara = swap = 0;
  for (size_t i = 0; i < n-1; i++) {
    for (size_t j = i + 1; j < n; j++) {
      compara++;
      if (A[i] > A[j]) {
        std::swap(A[i], A[j]);
        swap++;
      }
    }
  }
}

// O(n^2) peor caso
template<class T>
void AlgorithmSort<T>::selectionSort(std::vector<T> &A, size_t n, size_t &compara, size_t &swap) {
  compara = swap = 0;
  for (size_t i = 0; i < n-1; i++) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < n; j++) {
      compara++;
      if (A[j] < A[minIndex])
        minIndex = j;
    }
    std::swap(A[minIndex], A[i]);
    swap++;
  }
}


#endif   // _ALGORITHM_SORT_H_
