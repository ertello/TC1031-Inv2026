#ifndef _STACKLL_H_
#define _STACKLL_H_

#include <iostream>
#include <stdexcept>
#include "NodeStack.h"

template <class T> 
class StackLL {
  private:
    NodeStack<T> *top; // apunta al primer nodo del stack
    NodeStack<T> *tail; // apunta al ultimo nodo del stack
    int numElements;
  public:
    StackLL();
    ~StackLL();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int position);
    T getData(int position);
    void updateData(T value, T newValue);
    // To do
    void updateAt(int position);
};

// Complejidad O(1)
template <class T>
StackLL<T>::StackLL() {
  std::cout << "-->Constructor StackLL llamado automaticamente: " << this << std::endl;
  top = nullptr;
  tail = nullptr;
  numElements = 0;
}

// Complejidad O(n)
template <class T>
StackLL<T>::~StackLL() {
  std::cout << "-->Destructor StackLL llamado automaticamente: " << this << std::endl;
  NodeStack<T> *p = top, *q = nullptr;
  while(p != nullptr) {
    q = p->next;
    //std::cout << "Liberando nodo: " << p->data << std::endl;
    delete p;
    p = q;
  }
  top = nullptr;
  tail = nullptr;
  numElements = 0;
}

// Complejidad O(1)
template <class T>
int StackLL<T>::getNumElements() {
  return numElements;
}

// Complejidad O(n)
template <class T>
void StackLL<T>::printList() {
  if (top == nullptr && tail == nullptr)
    std::cout << "La lista esta vacia" << std::endl;
  else {
    std::cout << "El contenido de la lista es:" << std::endl;
    NodeStack<T> *p = top;
    while(p != nullptr) {
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
  }  
}

// Complejidad O(1)
template <class T>
void StackLL<T>::addFirst(T value) {
  // 1. crear nuevo nodo en memoria
  NodeStack<T> *newNode = new NodeStack<T>(value);
  // 2. apuntar newNode->next al nodo apuntado por top
  newNode->next = top;
  // 3. actualizar top para apuntar a newNode
  top = newNode;
  if (numElements == 0)
    tail = newNode;
  numElements++;
}

// Complejidad O(1)
template <class T>
void StackLL<T>::addLast(T value) {
  // La lista esta vacia
  if (top == nullptr && tail == nullptr)
    addFirst(value);
  else {
    // 1. crear nuevo nodo en memoria
    NodeStack<T> *newNode = new NodeStack<T>(value);
    // 2. apuntar tail->next a newNode
    tail->next = newNode;
    // 3. actualizar tail para apuntar a newNode
    tail = newNode;
    numElements++;
  }
}

// Complejidad O(n)
template <class T>
bool StackLL<T>::deleteData(T value) {
  // La lista esta vacia
  if (top == nullptr && tail == nullptr) {
    std::cout << "La lista esta vacia" << std::endl;
    return false;
  }
  // Buscar el nodo con value en la lista
  NodeStack<T> *p = top, *prev = nullptr;
  while (p != nullptr && p->data != value) {
    prev = p;
    p = p->next;
  }
  // Nodo con value no encontrado
  if (p == nullptr) {
    std::cout << "El valor no existe en la lista" << std::endl;
    return false;
  }
  // Caso 1: borrar el primer nodo de la lista
  if (p == top) {
    top = p->next;
    if (top == nullptr) // Si la lista contiene un solo nodo
      tail = nullptr;
  }
  // Caso 2: borrar el ultimo nodo de la lista
  else if (p == tail) {
    prev->next = nullptr;
    tail = prev;
  }
  // Caso 3: borrar nodo intermedio de la lista
  else {
    prev->next = p->next;
  }
  // Finalmente borramos el nodo apuntado por p
  delete p;
  p = nullptr;
  numElements--;
  return true;
}

// Complejidad O(n)
template <class T>
bool StackLL<T>::deleteAt(int position) {
  // La lista esta vacia
  if (top == nullptr && tail == nullptr)
    throw std::out_of_range("La lista esta vacia");
  // Posicion invalida
  if (position < 0 || position >= numElements)
    throw std::out_of_range("Posicion invalida");
  // Avanzar hasta el nodo en la posicion indicada
  NodeStack<T> *p = top, *prev = nullptr;
  for (int i = 0; i < position; i++) {
    prev = p;
    p = p->next;
  }
  // Caso 1: borrar el primer nodo de la lista
  if (p == top) {
    top = p->next;
    if (top == nullptr) // Si la lista contiene un solo nodo
      tail = nullptr;
  }
  // Caso 2: borrar el ultimo nodo de la lista
  else if (p == tail) {
    prev->next = nullptr;
    tail = prev;
  }
  // Caso 3: borrar nodo intermedio de la lista
  else {
    prev->next = p->next;
  }
  // Finalmente borramos el nodo apuntado por p
  delete p;
  p = nullptr;
  numElements--;
  return true;
}

// Complejidad O(n)
template <class T>
T StackLL<T>::getData(int position) {
  // La lista esta vacia
  if (top == nullptr && tail == nullptr)
    throw std::out_of_range("La lista esta vacia");
  // Posicion invalida
  if (position < 0 || position >= numElements)
    throw std::out_of_range("Posicion invalida");
  // Avanzar hasta el nodo en la posicion indicada
  NodeStack<T> *p = top;
  for (int i = 0; i < position; i++)
    p = p->next;
  return p->data;
}

// Complejidad O(n)
template <class T>
void StackLL<T>::updateData(T value, T newValue) {
  // La lista esta vacia
  if (top == nullptr && tail == nullptr)
    throw std::out_of_range("La lista esta vacia");
  // Buscar el nodo con value en la lista
  NodeStack<T> *p = top;
  while (p != nullptr && p->data != value)
    p = p->next;
  // Nodo con value no encontrado
  if (p == nullptr)
    throw std::out_of_range("El elemento a actualizar no existe en la lista");
  // Actualizar eñ dato encontrado
  p->data = newValue;
}

#endif // _STACKLL_H_