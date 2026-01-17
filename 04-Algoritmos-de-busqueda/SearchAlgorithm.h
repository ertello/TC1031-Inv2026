#ifndef _SEARCH_ALGORITHM_H_
#define _SEARCH_ALGORITHM_H_

#include <iostream>
#include <vector>

template <class T>
class SearchAlgorithm {
  public:
    SearchAlgorithm();
    ~SearchAlgorithm();
    int busquedaSecuencial(const std::vector<T> &A, T key, size_t &compara);
    int busquedaSecuencialVectorOrdenado(const std::vector<T> &A, T key, size_t &compara);
    int busquedaBinaria(const std::vector<T> &A, T key, size_t &compara);
    int busquedaBinariaRecursiva(const std::vector<T> &A, size_t low, size_t high, T key, size_t &compara);
};

template <class T>
SearchAlgorithm<T>::SearchAlgorithm() {

}

template <class T>
SearchAlgorithm<T>::~SearchAlgorithm() {

}

// O(n) peor caso
template <class T>
int SearchAlgorithm<T>::busquedaSecuencial(const std::vector<T> &A, T key, size_t &compara) {
  compara = 0;
  size_t i = 0;
  while (i < A.size() && A[i] != key) {
    compara++;
    i++;
  }
  if (i < A.size())
    return i;
  else
    return -1;
}

// O(n/2) peor caso
template <class T>
int SearchAlgorithm<T>::busquedaSecuencialVectorOrdenado(const std::vector<T> &A, T key, size_t &compara) {
  compara = 0;
  for (size_t i = 0; i < A.size(); i++) {
    compara++;
    if (key <= A[i]) {
      compara++;
      if (key == A[i])
        return i;
      else
        return -1;
    }
  }
  return -1;
}

// O(log n) peor caso
template <class T>
int SearchAlgorithm<T>::busquedaBinaria(const std::vector<T> &A, T key, size_t &compara) {
  compara = 0;
  size_t l = 0;
  size_t r = A.size() - 1;
  while (l <= r) {
    size_t m = l + (r - l) / 2;
    compara++;
    if (key == A[m])
      return m;
    else if (key < A[m])
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}

// O(log n) peor caso
template <class T>
int SearchAlgorithm<T>::busquedaBinariaRecursiva(const std::vector<T> &A, size_t low, size_t high, T key, size_t &compara) {
  if (low > high)
    return -1;
  size_t m = low + (high - low) / 2;
  compara++;
  if (key == A[m]) 
    return m;
  else if (key < A[m])
    return busquedaBinariaRecursiva(A, low, m-1, key, compara);
  else 
    return busquedaBinariaRecursiva(A, m+1, high, key, compara);
}



  
#endif  // _SEARCH_ALGORITHM_H_
