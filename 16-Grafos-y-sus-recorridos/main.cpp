/** 
* Ejemplo que implementa Grafos representados como lista de adyacencia y el recorrido DFS
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main < TestCases/graph01.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < TestCases/graph01.txt
**/

#include <iostream>
#include <sstream>
#include "Graph.h"

int main() {
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf();
  // Construye un grafo
  Graph<std::string> g1;
  // Lee de archivo un grafo, directed=1, weighted=1
  // lista de adyacencia
  g1.readGraph(inputInfo, 1, 1);
  g1.print();
  g1.DFS(3); // nodo es cero basado
  std::cout << std::endl;
  return 0;
}