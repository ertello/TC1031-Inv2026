#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include "NodeDLL.h"

template <class T>
class DoubleLinkedList {
  private:
    NodeDLL<T> *head;
    NodeDLL<T> *tail;
    int numElements;

  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    int getNumElements() const;
    void printList() const;
    void printReverseList() const;
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int position);
    T getData(int position) const;
    void updateData(T oldValue, T newValue);
    // To-do Act 2.1 y 2.2 
    void updateAt(int position);
    int findData(T value);
    void sort();
    void invert();
    T getProductSublist(int inicio, int fin);
    // https://stackoverflow.com/questions/40798378/c-deep-copying-linked-list
    DoubleLinkedList(const DoubleLinkedList<T>& other);
    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other);
};

// Complejidad O(1)
template <class T>
DoubleLinkedList<T>::DoubleLinkedList() {
  std::cout << "-->Constructor DoubleLinkedList llamado automaticamente: " << this << std::endl;
  head = tail = nullptr;
  numElements = 0;
}

// Complejidad O(n)
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  std::cout << "-->Destructor DoubleLinkedList llamado automaticamente: " << this << std::endl;
  NodeDLL<T> *p = head, *q = nullptr;
  while(p != nullptr) {
    q = p->next;
    //std::cout << "Liberando nodo: " << p->data << " ...";
    delete p;
    p = q;
  }
  head = tail = nullptr;
  numElements = 0;
}

// Complejidad O(1)
template <class T>
int DoubleLinkedList<T>::getNumElements() const {
  return numElements;  
}

// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::printList() const {
  if (head == nullptr && tail == nullptr)
    std::cout << "La lista esta vacia" << std::endl;
  else {
    std::cout << "El contenido de la lista es: " << std::endl;
    NodeDLL<T> *p = head;
    while(p != nullptr) {
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
  }    
}

#endif // _DOUBLELINKEDLIST_H_
