#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include "LinkedList.h"
#include "StackLL.h"

template <class T> 
class Graph {
private:
  int numNodes;
  int numEdges;
  int directedGraph;  // 1 dirigido; 0 no-dirigido
  int weightedGraph;  // 1 ponderado; 0 no-ponderado
  // Cada nodo tiene un id y un objeto de datos tipo T
  std::map<int, T> nodesInfo;
  // Lista de adyacencia (vector de listas de pares <nodo,peso>)
  std::vector<LinkedList<std::pair<int, int>>> adjList;

  void split(std::string line, std::vector<int> &res);
  
public:
  Graph();
  ~Graph();
  void readGraph(std::istream &input, int _directed, int _weighted);
  void print(int flagInfo = 0);
  void DFS(int v); // vertice cero basado
  // To-do act 4.1 y 4.2
  void BFS(int v);
  // https://www.geeksforgeeks.org/dsa/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
  // https://www.youtube.com/watch?v=K_1urzWrzLs&t=40s
  std::pair<std::vector<int>, std::vector<int>> shortestPath(int v); // Algoritmo de Dijkstra
};

// O(1)
template <class T> 
Graph<T>::Graph() {
  numNodes = 0;
  numEdges = 0;
  directedGraph = 1;
  weightedGraph = 1;
}

// O(1)
template <class T> 
Graph<T>::~Graph() {
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
  directedGraph = 1;
  weightedGraph = 1;
}
// O(k), k - numero de elementos en la linea
template <class T>
void Graph<T>::split(std::string line, std::vector<int> &res) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

// O(n+m), n - numero de nodos, m - numero de aristas
template <class T>
void Graph<T>::readGraph(std::istream &input, int _directed, int _weighted) {
  directedGraph = _directed;
  weightedGraph = _weighted;
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) { // Ignorar primera linea de texto (comentario)
      i++;
      continue;
    }
    if (i == 1) { // Leemos numNodes y numEdges
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[1];
      // Reservar memoria para los numNodes renglones (cero basado) y 
      // listas vacias de pares (nodo, peso) 
      adjList.resize(numNodes, LinkedList<std::pair<int, int>>());
      i++;
      continue;
    }
    if (i > 1 && i < numNodes + 2) { // Para cada nodo se lee su informacion
      T data = line; // ATENCION: convertir al tipo de dato adecuado
      // map <key, data> con los nodos indexados cero basados
      nodesInfo.insert(std::make_pair(i - 2, data));
      i++;
      continue;
    }
    // Lee las aristas
    std::vector<int> res;
    split(line, res);
    // nodos cero basados
    int nodeU = res[0] - 1;
    int nodeV = res[1] - 1;
    // Si el grafo es ponderado se lee tambien el peso
    // grafo no ponderado entonces aristas con peso 1
    int weight = (weightedGraph == 1) ? res[2] : 1;
    // Siempre se agrega la arista (nodeU, nodeV)
    adjList[nodeU].addLast(std::make_pair(nodeV, weight));
    // Si el grafo es no dirigido agrega tambien la arista (nodeV, nodeU)
    if (directedGraph == 0)
      adjList[nodeV].addLast(std::make_pair(nodeU, weight));
    i++;
  }
}

// O(nm), n - numero de nodos, m - numero de aristas
template <class T> 
void Graph<T>::print(int flagInfo) {
  std::cout << "numNodes: " << numNodes << std::endl;
  std::cout << "numEdges: " << numEdges << std::endl;
  std::cout << "Adjacency List" << std::endl;
  for (int nodeU = 0; nodeU < numNodes; nodeU++) {
    if (flagInfo) // Se imprime la info del nodo
      std::cout << "vertex " << nodesInfo[nodeU] << ": ";
    else // Se imprime el numero de nodo
      std::cout << "vertex " << nodeU + 1 << ": ";
    NodeLinkedList<std::pair<int, int>> *ptr = adjList[nodeU].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      int nodeV = par.first;
      int weight = par.second;
      std::string nodeData = (flagInfo) ? nodesInfo[nodeV] + ", " : "";
      if (weightedGraph == 1) // grafo ponderado
        std::cout << "{" << nodeData << nodeV + 1 << ", " << weight << "} ";
      else
        std::cout << "{" << nodeData << nodeV + 1 << "} ";
      ptr = ptr->next;
    }
    std::cout << std::endl;
  }
}

// O(n+m) donde n=|V| y m=|E|
// recibe un vertice cero basado
template <class T> 
void Graph<T>::DFS(int v) {
  // Declaramos un stack
  StackLL<int> stack;
  // Declaramos un conjunto (set) del STL de C++ (elementos unicos y ordenados)
  std::set<int> visited;
  // Marcar como visitado el vertice de partida y meterlo en el stack
  stack.push(v);
  std::cout << "Recorrido DFS: " << std::endl;
  while (!stack.isEmpty()) {
    // Extraer un vertice del stack
    v = stack.peek();
    stack.pop();
    // Procesar el vertice si no ha sido visitado
    bool isVisited = visited.find(v) != visited.end();
    if (!isVisited) { // No ha sido visitado
      visited.insert(v);
      std::cout << v+1 << ", ";
    }
    //Obtener vecinos del vertice v
    // Si estos no han sido visitados marcarlos como visitados
    // y los metemos al stack
    NodeLinkedList<std::pair<int, int>> *ptr = adjList[v].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      int u = par.first;
      bool isVisited = visited.find(u) != visited.end();
      if (!isVisited) { // No ha sido visitado
        stack.push(u);
      }
      ptr = ptr->next;
    }
  }
  std::cout << std::endl;
}

#endif // _GRAPH_H_
