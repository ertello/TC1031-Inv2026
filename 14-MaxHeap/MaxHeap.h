#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <iostream>
#include <stdexcept>
#include <vector>

template <class T>
class MaxHeap {
  private:
    // contiene los elementos del maxheap
    std::vector<T> data;
    // capacidad maxima del maxheap
    int maxCapacity;
    // tamaño actual del maxheap
    int currentSize;

    int parent(int k);
    int left(int k);
    int right(int k);

  public:
    MaxHeap();
    MaxHeap(int _maxCapacity);
    ~MaxHeap();
    int getMaxCapacity();
    void print();
    void push(T value);
    // TO-DO Act 3.2
    void pop();
    T getTop();
    bool isEmpty();
    int size();
    // maxHeap(std::vector<T> lista) construye un heap a partir de una lista (vector)

};

//O(1)
template <class T>
MaxHeap<T>::MaxHeap() {
  data.clear();
  maxCapacity = 0;
  currentSize = 0;
}

//O(1)
template <class T>
MaxHeap<T>::MaxHeap(int _maxCapacity) {
  data.resize(_maxCapacity);
  maxCapacity = _maxCapacity;
  currentSize = 0;
}

//O(1)
template <class T>
MaxHeap<T>::~MaxHeap() {
  data.clear();
  maxCapacity = 0;
  currentSize = 0;
}

//O(1)
template <class T>
int MaxHeap<T>::parent(int k) {
  return (k - 1) / 2;
}

//O(1)
template <class T>
int MaxHeap<T>::left(int k) {
  return (2 * k + 1);
}

//O(1)
template <class T>
int MaxHeap<T>::right(int k) {
  return (2 * k + 2);
}

// O(1)
template <class T> 
int MaxHeap<T>::getMaxCapacity() { 
  return maxCapacity; 
}

// O(n)
template <class T> void MaxHeap<T>::print() {
  std::cout << "Contenido del maxheap:" << std::endl;
  for (int i = 0; i < currentSize; i++) {
    std::cout << data[i] << ", ";
  }
  std::cout << std::endl;
}

// O(log n)
template <class T> void MaxHeap<T>::push(T key) {
  if (currentSize == maxCapacity) {
    throw std::out_of_range("Overflow: no es posible insertar la llave");
  }
  // Insertar la nueva llave al final del vector
  int k = currentSize;
  data[k] = key;
  currentSize++;
  // Reparar propiedades del maxheap si son violadas
  while(k != 0 && data[parent(k)] < data[k]) {
    std::swap(data[k], data[parent(k)]);
    k = parent(k);
  }
}

#endif // _MAXHEAP_H_