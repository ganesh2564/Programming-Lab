#include "List.h"
#include <iostream>
using namespace std;

template <class T>
class Graph {
  int numVertices;
  typename List<T>::doublyLl *adjLists;
  bool *visited;

public:
  Graph(T vertices);
  void addEdge(T src, T dest);
  void DFS(T startVertex);
};

template <class T>
Graph<T>::Graph(T vertices) {
  numVertices = vertices;
  adjLists = new typename List<T>::doublyLl[vertices];
}

template <class T>
void Graph<T>::addEdge(T src, T dest) {
  adjLists[src].addElement(dest);
  adjLists[dest].addElement(src);
}

template <class T>
void Graph<T>::DFS(T startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  List<int>::stack stk;

  visited[startVertex] = true;
  stk.pushstk(startVertex);

  while (stk.head) {
    T currVertex = stk.pop();
    cout << "Visited " << currVertex << " ";

    typename List<int>::doublyLl::Node *i;

    for (i = adjLists[currVertex].head; i != nullptr; i = i->next) {
      T adjVertex = i->data;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        stk.pushstk(adjVertex);
      }
    }
  }
}

int main() {
  Graph<int> g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.DFS(2);

  return 0;
}
